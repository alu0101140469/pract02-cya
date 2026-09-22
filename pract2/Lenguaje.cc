// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Daniel Palenzuela Álvarez
// Correo: alu0101140469@ull.edu.es
// Fecha: 22/09/2026
// Archivo Lenguaje.cc: implementación de la clase Lenguaje.
// Gestiona la inserción y E/S del conjunto de cadenas que representa.
// Historial de revisiones
// 22/09/2026 - Creación del código.

#include "Lenguaje.h"

#include <cctype>
#include <istream>
#include <ostream>
#include <string>

namespace {

/**
 * @brief Elimina los espacios en blanco al inicio y al final de una cadena.
 * @param text Cadena que se desea limpiar.
 */
void Trim(std::string& text) {
  std::size_t begin = 0;
  while (begin < text.size() &&
         std::isspace(static_cast<unsigned char>(text[begin]))) {
    ++begin;
  }

  // Se busca el último carácter no blanco desde el final de la cadena.
  std::size_t end = text.size();
  while (end > begin &&
         std::isspace(static_cast<unsigned char>(text[end - 1]))) {
    --end;
  }

  text = text.substr(begin, end - begin);
}

}  // namespace para funciones auxiliares

/**
 * @brief Construye un lenguaje vacío.
 */
Lenguaje::Lenguaje() : cadenas_() {}

/**
 * @brief Inserta una cadena en el lenguaje.
 * @param cadena Cadena que se desea insertar.
 */
void Lenguaje::Insertar(const Cadena& cadena) {
  cadenas_.insert(cadena);
}

/**
 * @brief Comprueba si el lenguaje es vacío.
 * @return true si no contiene cadenas.
 */
bool Lenguaje::EsVacio() const {
  return cadenas_.empty();
}

/**
 * @brief Sobrecarga del operador de entrada para leer un lenguaje desde un flujo.
 * @param in Flujo de entrada.
 * @param lenguaje Lenguaje que recibirá las cadenas.
 * @return Referencia al flujo de entrada.
 */
std::istream& operator>>(std::istream& in, Lenguaje& lenguaje) {
  char opening = '\0';

  // Se espera que el lenguaje comience con {.
  if (!(in >> opening) || opening != '{') {
    in.setstate(std::ios::failbit);
    return in;
  }

  // Se lee el contenido del lenguaje hasta encontrar }.
  Lenguaje resultado;
  std::string content;

  if (!std::getline(in, content, '}')) {
    return in;
  }

  // Se procesan los elementos separados por comas.
  std::size_t begin = 0;

  // Se recorre la cadena de contenido para extraer cada elemento.
  while (begin <= content.size()) {
    const std::size_t separator = content.find(',', begin);

    // Se obtiene el elemento actual, eliminando los espacios en blanco.
    std::string item = content.substr(
        begin,
        separator == std::string::npos
            ? std::string::npos
            : separator - begin);

    // Se eliminan los espacios en blanco al inicio y al final del elemento.
    Trim(item);

    // Se inserta la cadena en el lenguaje si no está vacía.
    if (!item.empty()) {
      resultado.Insertar(Cadena(item));
    }

    // Si no se encuentra un separador, se ha procesado el último elemento.
    if (separator == std::string::npos) {
      break;
    }

    // Se actualiza el índice de inicio para el siguiente elemento.
    begin = separator + 1;
  }

  // Se asigna el resultado al lenguaje de salida.
  lenguaje = resultado;
  return in;
}

/**
 * @brief Sobrecarga del operador de salida para escribir un lenguaje en un flujo.
 * @param out Flujo de salida.
 * @param lenguaje Lenguaje que se desea escribir.
 * @return Referencia al flujo de salida.
 */
std::ostream& operator<<(std::ostream& out, const Lenguaje& lenguaje) {
  out << '{';

  // Se utiliza un indicador para controlar la colocación de comas entre elementos.
  bool first = true;

  // Se recorre el conjunto de cadenas del lenguaje para escribir cada una.
  for (const Cadena& cadena : lenguaje.cadenas_) {
    if (!first) {
      out << ", ";
    }

    // Se escribe la cadena en el flujo, utilizando & para representar la cadena vacía.
    out << cadena;
    first = false;
  }

  // Se cierra la representación del lenguaje con }.
  out << '}';
  return out;
}