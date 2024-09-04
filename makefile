SRC_DIR = ./src
INC_DIR = ./inc
OUT_DIR = ./build
OBJ_DIR = $(OUT_DIR)/obj

CFLAGS = -Wall

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

.DEFAULT_GOAL := all

-include $(patsubst %.o,%.d,$(OBJ_FILES))

all: $(OBJ_FILES)
	@echo Enlazando $@
	@gcc $(OBJ_FILES) -o $(OUT_DIR)/app.elf

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo Compilando $<
	@mkdir -p $(OBJ_DIR)
	@gcc -o $@ -c $< -I$(INC_DIR) -MMD -DUSE_STATIC_MEM -DMAX_GPIO_INSTANCES=10

.PHONY: clean
clean:
	@rm -f -r $(OUT_DIR)

doc:
	@mkdir -p $(OUT_DIR)
	@doxygen Doxyfile
