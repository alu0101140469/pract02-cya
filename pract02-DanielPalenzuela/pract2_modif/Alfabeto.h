// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Daniel Palenzuela Álvarez
// Correo: alu0101140469@ull.edu.es
// Fecha: 22/09/2026
// Archivo Alfabeto.h: definición de la clase Alfabeto.
// Representa un alfabeto como un conjunto de símbolos y proporciona la
// interfaz básica para insertar y consultar símbolos, además de E/S.
// Historial de revisiones
// 22/09/2026 - Creación del código.

#ifndef ALFABETO_H_
#define ALFABETO_H_

#include <iosfwd>
#include <set>
#include <string>

/**
 * @file Alfabeto.h
 * @brief Declaración de la clase Alfabeto.
 */

/**
 * @class Alfabeto
 * @brief Representa un conjunto finito de símbolos.
 *
 * La estructura de datos interna permanece oculta al cliente de la clase.
 */
class Alfabeto {
 public:
  /**
   * @brief Tipo utilizado para representar un símbolo.
   */
  using Simbolo = char;

  /**
   * @brief Construye un alfabeto vacío.
   */
  Alfabeto();

  /**
   * @brief Construye un alfabeto a partir de una secuencia de símbolos.
   * @param symbols Secuencia de caracteres que formará el alfabeto.
   */
  explicit Alfabeto(const std::string& symbols);

  /**
   * @brief Comprueba si un símbolo pertenece al alfabeto.
   * @param simbolo Símbolo que se desea consultar.
   * @return true si el símbolo pertenece al alfabeto.
   */
  bool Contiene(Simbolo simbolo) const;

  /**
   * @brief Inserta un símbolo en el alfabeto.
   * @param simbolo Símbolo que se desea insertar.
   * @return true si se realiza una inserción, false si ya estaba presente o
   *         si es el símbolo reservado &.
   */
  bool Insertar(Simbolo simbolo);

  /**
   * @brief Lee un alfabeto desde un flujo.
   * @param in Flujo de entrada.
   * @param alfabeto Alfabeto que recibirá los símbolos.
   * @return El flujo de entrada recibido.
   */
  friend std::istream& operator>>(std::istream& in, Alfabeto& alfabeto);

  /**
   * @brief Escribe un alfabeto en un flujo.
   * @param out Flujo de salida.
   * @param alfabeto Alfabeto que se desea escribir.
   * @return El flujo de salida recibido.
   */
  friend std::ostream& operator<<(std::ostream& out, const Alfabeto& alfabeto);

 private:
 // Conjunto de símbolos que forman el alfabeto.
  std::set<Simbolo> symbols_;
};

#endif