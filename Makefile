## Hanged Bunny Studio Library ------    ---  -- --- -    ---  --    - -- -   -
## Hanged Bunny Studio 2014-2016 ----- -- - -- -  -  -- -- - -- --  -- -- -- --
## ----------------------------------- -- -    - - - -- -- - -- ---- -    -- --
## ----------------------------------    -- -- - --- -    ---  --   -- -- -   -
## ----------------------------------------------------------------------------

## ----------------------------------------------------------------------------
## Configuration --------------------------------------------------------------

  MOD		=	game.exe
  BIN		=	game.exe
#  FLAG		=	-W -Wall -std=gnu11 -O2 -ffast-math
  FLAG		=	-W -Wall -std=gnu11 -g -g3 -ggdb

  INCLUDE	=	-I$(HOME)/.froot/include/ -I$(PWD) -I$(PWD)/include/
  SRC		=	$(wildcard */*.c) $(wildcard */*/*.c)
  OBJ		=	$(SRC:.c=.o)
  LIBPATH	=	-L${HOME}/.froot/lib/

  ## Rules ------------------------------------------------------------------
  all:		bin
  bin:		$(OBJ)
		@bcc $(OBJ) -o $(BIN) $(LIBPATH) $(FLAG)
		@echo "[OUT] " $(BIN)
		@echo $(BIN) | tr '[:lower:]' '[:upper:]'
  .c.o:
		@bcc $(INCLUDE) $(FLAG) -c $< -o $@
		@echo "[BUNNYCC]" $<
  clean:
		@rm -f $(OBJ)
  fclean:	clean
		@rm -f $(BIN)
  re:		fclean all

## ----------------------------------------------------------------------------
## MISC -----------------------------------------------------------------------

  .PHONY: all clean fclean re

  .SUFFIXES: .cpp .o
