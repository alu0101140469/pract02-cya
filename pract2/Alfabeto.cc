// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Daniel Palenzuela Álvarez
// Correo: alu0101140469@ull.edu.es
// Fecha: 22/09/2026
// Archivo Alfabeto.cc: implementación de la clase Alfabeto.
// Implementa la consulta, inserción y E/S de símbolos manteniendo oculta
// Historial de revisiones
// 22/09/2026 - Creación del código.

#include "Alfabeto.h"

#include <istream>
#include <ostream>

/**
 * @file Alfabeto.cc
 * @brief Implementación de la clase Alfabeto.
 */
Alfabeto::Alfabeto() : symbols_() {}

/**
 * @brief Construye un alfabeto a partir de una secuencia de símbolos.
 * @param symbols Secuencia de caracteres que formará el alfabeto.
 */
Alfabeto::Alfabeto(const std::string& symbols) : symbols_() {
  for (const Simbolo simbolo : symbols) {
    Insertar(simbolo);
  }
}

/**
 * @brief Comprueba si un símbolo pertenece al alfabeto.
 * @param simbolo Símbolo que se desea consultar.
 * @return true si el símbolo pertenece al alfabeto.
 */
bool Alfabeto::Contiene(const Simbolo simbolo) const {
  return symbols_.find(simbolo) != symbols_.end();
}

/**
 * @brief Inserta un símbolo en el alfabeto.
 * @param simbolo Símbolo que se desea insertar.
 * @return true si se realiza una inserción, false si ya estaba presente o
 *         si es el símbolo reservado &.
 */
bool Alfabeto::Insertar(const Simbolo simbolo) {
  if (simbolo == '&') {
    return false;
  }

  return symbols_.insert(simbolo).second;
}

/**
 * @brief Sobrecarga del operador de entrada para leer un alfabeto desde un flujo.
 * @param in Flujo de entrada.
 * @param alfabeto Objeto Alfabeto donde se almacenarán los símbolos leídos.
 * @return Referencia al flujo de entrada.
 */
std::istream& operator>>(std::istream& in, Alfabeto& alfabeto) {
  std::string symbols;

  if (in >> symbols) {
    alfabeto = Alfabeto(symbols);
  }

  return in;
}

/**
 * @brief Sobrecarga del operador de salida para escribir un alfabeto en un flujo.
 * @param out Flujo de salida.
 * @param alfabeto Objeto Alfabeto que se desea escribir.
 * @return Referencia al flujo de salida.
 */
std::ostream& operator<<(std::ostream& out, const Alfabeto& alfabeto) {
  out << '{';

  bool first = true;
  for (const Alfabeto::Simbolo simbolo : alfabeto.symbols_) {
    if (!first) {
      out << ", ";
    }

    out << simbolo;
    first = false;
  }

  out << '}';
  return out;
}