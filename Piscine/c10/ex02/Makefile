OBJECTS = $(SRCS:.c=.o)
SRCS = main.c strs.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
TARGET = ft_tail

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(TARGET) : $(OBJECTS) 
	      $(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

all : $(TARGET)

clean :
	$(RM) $(OBJECTS)

fclean : clean
	$(RM) $(TARGET)

re : fclean all

.PHONY : all clean fclean re
