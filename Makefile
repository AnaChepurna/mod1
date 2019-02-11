  #  g++ -c main.cpp -I $HOME/mod1/SFML2.5.1/include
  #  g++ main.o -o sfml-app -L $HOME/mod1/SFML2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system

CC = g++
# CFLAGS = -Wall -Wextra -Werror
NAME = mod1
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
CURR_DIR = $(shell pwd)
SFML_INCL = $(CURR_DIR)/SFML2.5.1/include
SFML_LIB = $(CURR_DIR)/SFML2.5.1/lib
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system
SFML_FRAMWORK_DIR = $(CURR_DIR)/SFML2.5.1/Frameworks
SFML_FRAMEWORKS = SFML.framework \
				sfml-graphics.framework \
				sfml-system.framework \
				sfml-window.framework
OPENGL = -framework OpenGL
HOME_FRAMEWORK_DIR = $(HOME)/Library/Frameworks
EXTLIBS = $(CURR_DIR)/SFML2.5.1/extlibs
EXT_FRAMEWORKS = OpenAL.framework \
				freetype.framework \
				ogg.framework \
				vorbis.framework \
				vorbisenc.framework \
				vorbisfile.framework

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L $(SFML_LIB) $(SFML_FLAGS) $(OPENGL)

%.o: %.cpp
	$(CC) -o $@ -c $< -I $(SFML_INCL)

sfml:
	@ mkdir -p $(HOME_FRAMEWORK_DIR);

	@ test -d $(HOME_FRAMEWORK_DIR)/SFML.framework \
		&& echo "\033[32mdir SFML.framework already exist\033[39m" \
			|| make SFML.framework

	@ test -d $(HOME_FRAMEWORK_DIR)/sfml-graphics.framework \
		&& echo "\033[32mdir sfml-graphics.framework already exist\033[39m" \
			|| make sfml-graphics.framework

	@ test -d $(HOME_FRAMEWORK_DIR)/sfml-window.framework \
		&& echo "\033[32mdir sfml-window.framework already exist\033[39m" \
			|| make sfml-window.framework

	@ test -d $(HOME_FRAMEWORK_DIR)/sfml-system.framework \
		&& echo "\033[32mdir sfml-system.framework already exist\033[39m" \
			|| make sfml-system.framework

sfml-clean:
	@ rm -rf $(patsubst %,$(HOME_FRAMEWORK_DIR)/%, $(SFML_FRAMEWORKS))
	@ echo "\033[31msfml frameworks deleted\033[39m"

SFML.framework:
	@ cp -r $(SFML_FRAMWORK_DIR)/$@ $(HOME_FRAMEWORK_DIR)
	@ echo "\033[33m"$@ "copied\033[39m"

sfml-graphics.framework:
	@ cp -r $(SFML_FRAMWORK_DIR)/$@ $(HOME_FRAMEWORK_DIR)
	@ echo "\033[33m"$@ "copied\033[39m"

sfml-window.framework:
	@ cp -r $(SFML_FRAMWORK_DIR)/$@ $(HOME_FRAMEWORK_DIR)
	@ echo "\033[33m"$@ "copied\033[39m"

sfml-system.framework:
	@ cp -r $(SFML_FRAMWORK_DIR)/$@ $(HOME_FRAMEWORK_DIR)
	@ echo "\033[33m"$@ "copied\033[39m"

sfml-extlibs:
	@ cp -r $(patsubst %,$(EXTLIBS)/%, $(EXT_FRAMEWORKS)) $(HOME_FRAMEWORK_DIR)
	@ echo "\033[33m"$@ "copied\033[39m"

sfml-extlibs-clean:
	@ rm -rf $(patsubst %,$(HOME_FRAMEWORK_DIR)/%, $(EXT_FRAMEWORKS))
	@ echo "\033[31mextlibs deleted\033[39m"

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all