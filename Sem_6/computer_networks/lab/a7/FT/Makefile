SRC_DIR := src
BIN_DIR := build
PACKAGE := ft
JAR_FILE := ft.jar
MANIFEST := manifest.mf

SRC := $(wildcard $(SRC_DIR)/$(PACKAGE)/*.java)

JC := javac
JCFLAGS := -d $(BIN_DIR)/ -cp $(SRC_DIR)/

all:
	$(JC) $(JCFLAGS) $(SRC)
	jar cmf $(BIN_DIR)/$(MANIFEST) $(BIN_DIR)/$(JAR_FILE) -C $(BIN_DIR)/ $(PACKAGE)
	rm -r $(BIN_DIR)/$(PACKAGE)

clean:
	rm $(BIN_DIR)/$(JAR_FILE)
