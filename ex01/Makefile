.DEFAULT_GOAL := all

NAME := forms

CXX := c++

CXXFLAGS := -std=c++98 -Wall -Wextra -Werror

SOURCES_DIR := sources

SOURCES_SUBDIRS := $(shell find $(SOURCES_DIR) -type d)

SOURCES_NAMES := $(subst $(SOURCES_DIR)/,, $(foreach dir, $(SOURCES_SUBDIRS), $(wildcard $(dir)/*.cpp)))

SOURCES := $(addprefix $(SOURCES_DIR)/, $(SOURCES_NAMES))

OBJECTS_DIR := objects

OBJECTS_NAMES := $(SOURCES_NAMES:.cpp=.o)

OBJECTS := $(addprefix $(OBJECTS_DIR)/, $(OBJECTS_NAMES))

DEPENDANCIES_DIR := dependancies

DEPENDANCIES := $(patsubst %.c, $(DEPENDANCIES_DIR/%.d), $(SOURCES_NAMES))

INCLUDES := includes

SHELL := /bin/sh

.SUFFIXES:
.SUFFIXES: .cpp .o

.PHONY: getnames
getnames:
	@echo $(SOURCES_NAMES)

.PHONY: test
.SILENT: test
test:
	if which c++ ; then $(MAKE) re CXX=c++ ; else echo c++ not found; fi
	if which g++ ; then $(MAKE) re CXX=g++ ; else echo g++ not found; fi
	if which clang ++ ; then $(MAKE) re CXX=clang++ ; else echo clang++ not found;fi
	$(MAKE) fclean

.PHONY: all
all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -I $(INCLUDES) $(OBJECTS) -o $(NAME)

$(OBJECTS_DIR)/%.o: $(SOURCES_DIR)/%.cpp
	if [ ! -d "$$(dirname $@)" ] ; then mkdir -p "$$(dirname $@)" ; fi
	if [ ! -d "$$(dirname $(DEPENDANCIES_DIR)/$*.d)" ] ; \
	then mkdir -p "$$(dirname $(DEPENDANCIES_DIR)/$*.d)" ; fi
	$(CXX) $(CXXFLAGS) -I $(INCLUDES) $(OPTFLAGS) -c $< -o $@ -MD -MF $(DEPENDANCIES_DIR)/$*.d

.PHONY: clean
clean:
	$(RM) $(NAME)

.PHONY: fclean
fclean: clean
	$(RM) -r $(OBJECTS_DIR) $(DEPENDANCIES_DIR)

.PHONY: re
re: fclean
	$(MAKE)


-include $(DEPENDANCIES)
