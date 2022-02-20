OBJECTS = $(SRCS:.c=.o)
SRCS = srcs/main.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
INC = includes
TARGET = ft_display_file

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INC)

$(TARGET) : $(OBJECTS) 
	      $(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

all : $(TARGET)

clean :
	$(RM) $(OBJECTS)

fclean : clean
	$(RM) $(TARGET)

re : fclean all

.PHONY : all clean fclean re
