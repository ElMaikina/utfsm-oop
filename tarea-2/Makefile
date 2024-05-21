JFLAGS = -g
JC = javac --module-path C:/javafx-sdk-22.0.1/lib --add-modules javafx.controls,javafx.fxml,javafx.graphics App.java

.SUFFIXES: .java .class

.java.class:
	$(JC) $(JFLAGS) $*.java

run:
	java --module-path C:/javafx-sdk-22.0.1/lib --add-modules javafx.controls,javafx.fxml,javafx.graphics App


CLASSES = \
        App.java \
        Estado.java \
        Inventario.java \
        Item.java \
		Main.java \
		Mascota.java

default: classes

classes: $(CLASSES:.java=.class)

clean:
	$(RM) $*.class
