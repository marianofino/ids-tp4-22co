# Directories for source files, include files, build output, and object files
SRC_DIR = ./src       # Source files directory
INC_DIR = ./inc       # Include files directory
OUT_DIR = ./build     # Output directory for the final executable
OBJ_DIR = $(OUT_DIR)/obj # Directory for object files

# Lists all source files in the SRC_DIR and maps them to corresponding object files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c) # Collect all .c files in the source directory
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES)) # Convert .c file paths to .o file paths

# Sets the default goal for make, which is 'all'
.DEFAULT_GOAL := all

# Includes the dependency files generated during compilation to ensure proper rebuilds
-include $(patsubst %.o,%.d,$(OBJ_FILES))

# The 'all' target builds the project by compiling all object files and linking them into the final executable
all: $(OBJ_FILES)
	@echo Linking... $@ # Echo message indicating the start of the linking process
	@gcc $(OBJ_FILES) -o $(OUT_DIR)/app.elf # Link all object files into the final executable

# Rule to compile .c files into .o object files, generating dependency files (.d) as well
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo Compiling... $@ # Echo message indicating the start of the compilation process
	@mkdir -p $(OBJ_DIR) # Create the object directory if it doesn't exist
	@gcc -o $@ -c $< -I $(INC_DIR) -MMD # Compile the .c file into an object file, with include path and dependency file generation

# Clean up the build output by removing the output directory and its contents
clean:
	@echo Cleaning... $@ # Echo message indicating the start of the cleaning process
	@rm -r $(OUT_DIR) # Remove the output directory and all its contents

# Generate project documentation using Doxygen
doc:
	@echo Generating documentation... $@ # Echo message indicating the start of documentation generation
	@mkdir -p $(OUT_DIR) # Ensure the output directory exists for documentation
	@doxygen doxyfile # Run Doxygen to generate documentation based on the configuration file 'doxyfile'
