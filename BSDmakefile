#
# Universidade Federal do Rio de Janeiro
# Escola Politecnica
# Departamento de Eletronica e de Computacao
# EEL270 - Computacao II - Turma 2019/1
# Prof. Marcelo Luiz Drumond Lanza
# Autor: Leticia Tavares dos Santos
# Descricao: Makefile do FreeBSD
#
# $Author: leticia.santos $
# $Date: 2019/04/14 15:23:31 $
# $Log: BSDmakefile,v $
# Revision 1.16  2019/04/14 15:23:31  leticia.santos
# *** empty log message ***
#
# Revision 1.15  2019/04/14 15:10:48  leticia.santos
# *** empty log message ***
#
# Revision 1.14  2019/04/14 14:52:29  leticia.santos
# *** empty log message ***
#
# Revision 1.13  2019/04/14 02:02:11  leticia.santos
# *** empty log message ***
#
# Revision 1.12  2019/04/05 02:55:29  leticia.santos
# *** empty log message ***
#
# Revision 1.11  2019/04/05 02:35:23  leticia.santos
# *** empty log message ***
#
# Revision 1.10  2019/04/05 02:14:31  leticia.santos
# *** empty log message ***
#
# Revision 1.9  2019/04/04 14:00:58  leticia.santos
# *** empty log message ***
#
# Revision 1.8  2019/04/01 21:01:43  leticia.santos
# *** empty log message ***
#
# Revision 1.7  2019/03/30 02:44:10  leticia.santos
# *** empty log message ***
#
# Revision 1.6  2019/03/30 02:08:35  leticia.santos
# *** empty log message ***
#
# Revision 1.5  2019/03/30 01:50:39  leticia.santos
# *** empty log message ***
#
# Revision 1.4  2019/03/29 23:25:02  leticia.santos
# *** empty log message ***
#
# Revision 1.3  2019/03/29 22:53:12  leticia.santos
# *** empty log message ***
#
# Revision 1.2  2019/03/28 15:38:15  leticia.santos
# *** empty log message ***
#
# Revision 1.1  2019/03/28 12:28:31  leticia.santos
# Initial revision
#
#

OS = `uname -s`

#Compilar

.ifdef GCC
CC = gcc
LD = gcc

.elif CLANG
CC = clang
LD = clang

.else
CC = gcc
LD = gcc
.endif

#Linkeditar

CFLAGS = -Wall -std=c99
LFLAGS = -Wall -std=c99

#Dependencias

AULA0101OBJS = aula0101.o
AULA0102OBJS = aula0102.o
AULA0103OBJS = aula0103.o
AULA0104OBJS = aula0104.o
AULA0105OBJS = aula0105.o
AULA0106OBJS = aula0106.o
AULA0107OBJS = aula0107.o

AULA0202AOBJS = aula0201a.o aula0202.o
AULA0202BOBJS = aula0201b.o aula0202.o
AULA0202COBJS = aula0201c.o aula0202.o
AULA0202DOBJS = aula0201d.o aula0202.o

AULA0302AOBJS = aula0301a.o aula0302.o
AULA0302BOBJS = aula0301b.o aula0302.o
AULA0302COBJS = aula0301c.o aula0302.o
AULA0302DOBJS = aula0301d.o aula0302.o


AULA01 = aula0101\
         aula0102\
	 aula0103\
	 aula0104\
	 aula0105\
	 aula0106\
	 aula0107

AULA02 = aula0202a\
	 aula0202b\
	 aula0202c\
	 aula0202d

AULA03 = aula0302a\
	 aula0302b\
	 aula0302c\
	 aula0302d

EXECS = $(AULA01)\
	$(AULA02)\
	$(AULA03)

ALL = $(EXECS)

#Regra Implicita

.c.o:
	$(CC) $(CFLAGS) -c $<

all: $(ALL)


aula01: $(AULA01)


aula0101: $(AULA0101OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0101OBJS)
	cp $@ $@-$(OS)-$(CC)

aula0102: $(AULA0102OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0102OBJS)
	cp $@ $@-$(OS)-$(CC)

aula0103: $(AULA0103OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0103OBJS)
	cp $@ $@-$(OS)-$(CC)

aula0104: $(AULA0104OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0104OBJS)
	cp $@ $@-$(OS)-$(CC)

aula0105: $(AULA0105OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0105OBJS)
	cp $@ $@-$(OS)-$(CC)

aula0106: $(AULA0106OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0106OBJS)
	cp $@ $@-$(OS)-$(CC)

aula0107: $(AULA0107OBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0107OBJS)
	cp $@ $@-$(OS)-$(CC)


aula02: $(AULA02)

aula0202a: $(AULA0202AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202AOBJS)
	cp $@ $@-$(OS)-$(CC)

aula0202b: $(AULA0202BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202BOBJS)
	cp $@ $@-$(OS)-$(CC)

aula0202c: $(AULA0202COBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202COBJS)
	cp $@ $@-$(OS)-$(CC)

aula0202d: $(AULA0202DOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0202DOBJS)
	cp $@ $@-$(OS)-$(CC)


aula03: $(AULA03)

aula0302a: $(AULA0302AOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0302AOBJS)
	cp $@ $@-$(OS)-$(CC)


aula0302b: $(AULA0302BOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0302BOBJS)
	cp $@ $@-$(OS)-$(CC)


aula0302c: $(AULA0302COBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0302COBJS)
	cp $@ $@-$(OS)-$(CC)

aula0302d: $(AULA0302DOBJS)
	$(LD) $(LFLAGS) -o $@ $(AULA0302DOBJS)
	cp $@ $@-$(OS)-$(CC)


clean:
	rm -f *.o $(EXECS)

clean-all:
	rm -f *.o $(EXECS) *-FreeBSD-* *-Linux-*

clean-freebsd:
	rm -f *.o $(EXECS) *-FreeBSD-*

clean-linux:
	rm -f *.o $(EXECS) *-Linux-*
