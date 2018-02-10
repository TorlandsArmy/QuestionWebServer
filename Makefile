CC = gcc
LD = ld
FLAGS = -O2 -Wall
VERSION = v0.01

all:
	@echo
	@echo "-------------------------------------"
	@echo " QuestionWEBSERVER $(VERSION) by Torlands"
	@echo " < Torlands.LeoGomez@torlands.Army >"
	@echo " < Torlands.AxelVA@torlands.Army >"
	@echo " < Torlands.NegroTorlands@torlands.Army >"
	@echo " Try other distro | kali no te hace hacker :v"
	@echo "-------------------------------------"
	@echo
	@echo [* Compilando ..]
	@echo
	$(CC) -o questionwebserver questionwebserver.c $(FLAGS)
	@echo

install:
	@echo
	cp questionwebserver /usr/local/bin
	@echo

clean:
	@echo
	rm -f questionwebserver core
	@echo

