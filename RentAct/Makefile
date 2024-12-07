# Nombre del ejecutable
TARGET = RentAct

# Compilador y banderas
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -O2

# Directorios
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
LOGIN_DIR = $(SRC_DIR)/login
MENU_DIR = $(SRC_DIR)/menu

# Archivos fuente y objetos
SRCS = $(wildcard $(LOGIN_DIR)/*.cpp) $(wildcard $(MENU_DIR)/*.cpp) main.cpp
OBJS = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(notdir $(SRCS)))

# Regla principal
all: $(TARGET)

# Regla para construir el ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar archivos fuente a objetos
$(BUILD_DIR)/%.o: $(LOGIN_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

$(BUILD_DIR)/%.o: $(MENU_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

# Crear directorio build si no existe
$(BUILD_DIR):
	mkdir -p $@

# Regla para limpiar los archivos generados
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Phony targets
.PHONY: all clean
