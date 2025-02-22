#!/bin/bash

SRC_DIR="src"
BIN_DIR="binarios"
INSTALL_DIR="/bin"

for file in "$SRC_DIR"/*.cpp; do
    filename=$(basename "$file" .cpp)
    
    echo "Compilando $file..."
    g++ "$file" -o "$BIN_DIR/$filename"
    
    if [ $? -eq 0 ]; then
        echo "✅ $filename compilado correctamente en $BIN_DIR/"
        
        echo "Copiando $filename a $INSTALL_DIR..."
        sudo cp "$BIN_DIR/$filename" "$INSTALL_DIR/"
        
        sudo chmod +x "$INSTALL_DIR/$filename"
        echo "✅ $filename instalado en $INSTALL_DIR/"
    else
        echo "❌ Error al compilar $file"
    fi
done

echo "Instalación completada."
