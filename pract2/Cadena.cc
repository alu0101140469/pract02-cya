// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Daniel Palenzuela Álvarez
// Correo: alu0101140469@ull.edu.es
// Fecha: 22/09/2026
// Archivo Cadena.cc: implementación de la clase Cadena.
// Implementa longitud, inversa, prefijos, sufijos, validación, comparación y E/S.
// Historial de revisiones
// 22/09/2026 - Creación del código.

#include "Cadena.h"

#include "Lenguaje.h"

#include <istream>
#include <ostream>

/**
 * @file Cadena.cc
 * @brief Implementación de la clase Cadena.
 */
Cadena::Cadena() : symbols_(), alfabeto_() {}

/**
 * @brief Construye una cadena a partir de una secuencia de símbolos.
 * @param symbols Secuencia de símbolos, & representa la cadena vacía.
 */
Cadena::Cadena(const std::string& symbols) : symbols_(), alfabeto_() {
  if (symbols != "&") {
    symbols_ = symbols;
  }
}

/**
 * @brief Construye una cadena asociada a un alfabeto.
 * @param symbols Secuencia de símbolos, & representa la cadena vacía.
 * @param alfabeto Alfabeto asociado.
 */
Cadena::Cadena(const std::string& symbols, const Alfabeto& alfabeto)
    : symbols_(), alfabeto_(alfabeto) {
  if (symbols != "&") {
    symbols_ = symbols;
  }
}

/**
 * @brief Asocia un alfabeto a la cadena.
 * @param alfabeto Nuevo alfabeto asociado.
 */
void Cadena::AsociarAlfabeto(const Alfabeto& alfabeto) {
  alfabeto_ = alfabeto;
}

/**
 * @brief Calcula la longitud de la cadena.
 * @return Número de símbolos de la cadena.
 */
std::size_t Cadena::Longitud() const {
  return symbols_.size();
}

/**
 * @brief Calcula la cadena inversa.
 * @return Nueva cadena con los símbolos en orden inverso.
 */
Cadena Cadena::Inversa() const {
  Cadena resultado(*this);
  resultado.symbols_.assign(symbols_.rbegin(), symbols_.rend());
  return resultado;
}

/**
 * @brief Obtiene el lenguaje de prefijos de la cadena.
 * @return Lenguaje que contiene todos los prefijos, incluida &.
 */
Lenguaje Cadena::Prefijos() const {
  Lenguaje resultado;

  // Se generan todos los prefijos de la cadena, incluida la cadena vacía.
  for (std::size_t length = 0; length <= symbols_.size(); ++length) {
    resultado.Insertar(Cadena(symbols_.substr(0, length), alfabeto_));
  }

  return resultado;
}

/**
 * @brief Obtiene el lenguaje de sufijos de la cadena.
 * @return Lenguaje que contiene todos los sufijos, incluida &.
 */
Lenguaje Cadena::Sufijos() const {
  Lenguaje resultado;

  // Se generan todos los sufijos de la cadena, incluida la cadena vacía.
  for (std::size_t length = 0; length <= symbols_.size(); ++length) {
    // Se calcula el índice de inicio del sufijo.
    const std::size_t start = symbols_.size() - length;
    resultado.Insertar(Cadena(symbols_.substr(start, length), alfabeto_));
  }

  return resultado;
}

/**
 * @brief Comprueba si la cadena es válida según el alfabeto asociado.
 * @return true si todos los símbolos de la cadena pertenecen al alfabeto.
 */
bool Cadena::EsValida() const {
  for (const Alfabeto::Simbolo simbolo : symbols_) {
    if (!alfabeto_.Contiene(simbolo)) {
      return false;
    }
  }

  return true;
}

/**
 * @brief Compara dos cadenas.
 *
 * El orden prioriza la longitud y, cuando coincide, utiliza la comparación
 * alfanumérica de la secuencia de símbolos.
 * @param other Cadena con la que se compara.
 * @return true si esta cadena precede a other.
 */
bool Cadena::operator<(const Cadena& other) const {
  if (symbols_.size() != other.symbols_.size()) {
    return symbols_.size() < other.symbols_.size();
  }

  return symbols_ < other.symbols_;
}

/**
 * @brief Compara dos cadenas.
 * @param other Cadena con la que se compara.
 * @return true si ambas cadenas son iguales.
 */
bool Cadena::operator==(const Cadena& other) const {
  return symbols_ == other.symbols_;
}

/**
 * @brief Sobrecarga del operador de entrada para leer una cadena desde un flujo.
 * @param in Flujo de entrada.
 * @param cadena Objeto Cadena donde se almacenará la secuencia leída.
 * @return Referencia al flujo de entrada.
 */
std::istream& operator>>(std::istream& in, Cadena& cadena) {
  std::string symbols;

  // Se lee la secuencia de símbolos desde el flujo.
  if (in >> symbols) {
    cadena.symbols_.clear();

    // Se asigna la secuencia leída a la cadena, excepto si es el símbolo reservado &.
    if (symbols != "&") {
      cadena.symbols_ = symbols;
    }
  }

  return in;
}

/**
 * @brief Sobrecarga del operador de salida para escribir una cadena en un flujo.
 * @param out Flujo de salida.
 * @param cadena Objeto Cadena que se desea escribir.
 * @return Referencia al flujo de salida.
 */
std::ostream& operator<<(std::ostream& out, const Cadena& cadena) {
    // Se escribe la cadena en el flujo, utilizando & para representar la cadena vacía.
  if (cadena.symbols_.empty()) {
    out << '&';
  } else {
    out << cadena.symbols_;
  }

  return out;
}