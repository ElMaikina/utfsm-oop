JFLAGS = -g
JC = javac

.SUFFIXES: .java .class

.java.class:
	$(JC) $(JFLAGS) $*.java

run:
	java Main


CLASSES = \
        Estado.java \
        Inventario.java \
        Item.java \
		Main.java \
		Mascota.java

default: classes

classes: $(CLASSES:.java=.class)

clean:
	$(RM) $*.class
