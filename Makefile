# Makefile for set
#****************************************************************

CPPOPTIONS = -std=c++11 -g
LDOPTIONS =

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: test_rbt test_node test_dict test_movie test_query

test_rbt: rbt.h rbt.cpp test_rbt.cpp node.h node.cpp
	g++ $(CPPOPTIONS) -o test_rbt test_rbt.cpp

test_node: node.h node.cpp test_node.cpp
	g++ $(CPPOPTIONS) -o test_node test_node.cpp

test_dict: dict.h dict.cpp test_dict.cpp
	g++ $(CPPOPTIONS) -o test_dict test_dict.cpp

test_movie: movie.h movie.cpp test_movie.cpp
	g++ $(CPPOPTIONS) -o test_movie test_movie.cpp

test_query: movie.h movie.cpp query_movies.cpp dict.h dict.cpp rbt.h rbt.cpp
	g++ $(CPPOPTIONS) -o query_movies query_movies.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean: tidy
	rm -f *.o
