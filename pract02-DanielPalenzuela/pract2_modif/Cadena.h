// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Daniel Palenzuela Álvarez
// Correo: alu0101140469@ull.edu.es
// Fecha: 22/09/2026
// Archivo Cadena.h: definición de la clase Cadena.
// Representa una secuencia de símbolos asociada a un alfabeto y define
// las operaciones propias de las cadenas requeridas por la práctica.
// Historial de revisiones
// 22/09/2026 - Creación del código.

#ifndef CADENA_H_
#define CADENA_H_

#include "Alfabeto.h"

#include <cstddef>
#include <iosfwd>
#include <string>

class Lenguaje;

/**
 * @file Cadena.h
 * @brief Declaración de la clase Cadena.
 */

/**
 * @class Cadena
 * @brief Representa una secuencia finita de símbolos asociada a un alfabeto.
 *
 * La cadena vacía se representa externamente mediante &. Su representación
 * interna es una secuencia vacía.
 */
class Cadena {
 public:
  /**
   * @brief Construye la cadena vacía.
   */
  Cadena();

  /**
   * @brief Construye una cadena a partir de una secuencia de símbolos.
   * @param symbols Secuencia de símbolos, & representa la cadena vacía.
   */
  explicit Cadena(const std::string& symbols);

  /**
   * @brief Construye una cadena asociada a un alfabeto.
   * @param symbols Secuencia de símbolos, & representa la cadena vacía.
   * @param alfabeto Alfabeto asociado.
   */
  Cadena(const std::string& symbols, const Alfabeto& alfabeto);

  /**
   * @brief Asocia un alfabeto a la cadena.
   * @param alfabeto Nuevo alfabeto asociado.
   */
  void AsociarAlfabeto(const Alfabeto& alfabeto);

  /**
   * @brief Calcula la longitud de la cadena.
   * @return Número de símbolos de la cadena.
   */
  std::size_t Longitud() const;

  /**
   * @brief Calcula la cadena inversa.
   * @return Nueva cadena con los símbolos en orden inverso.
   */
  Cadena Inversa() const;

  /**
   * @brief Obtiene el lenguaje de prefijos de la cadena.
   * @return Lenguaje que contiene todos los prefijos, incluida &.
   */
  Lenguaje Prefijos() const;

  /**
   * @brief Obtiene el lenguaje de sufijos de la cadena.
   * @return Lenguaje que contiene todos los sufijos, incluida &.
   */
  Lenguaje Sufijos() const;

  // modif
  Lenguaje Subcadenas() const;

  /**
   * @brief Comprueba si la cadena está definida sobre su alfabeto.
   * @return true si todos sus símbolos pertenecen al alfabeto asociado.
   */
  bool EsValida() const;

  /**
   * @brief Compara dos cadenas.
   *
   * El orden prioriza la longitud y, cuando coincide, utiliza la comparación
   * alfanumérica de la secuencia de símbolos.
   * @param other Cadena con la que se compara.
   * @return true si esta cadena precede a other.
   */
  bool operator<(const Cadena& other) const;

  /**
   * @brief Comprueba la igualdad entre dos cadenas.
   * @param other Cadena con la que se compara.
   * @return true si ambas cadenas tienen la misma secuencia de símbolos.
   */
  bool operator==(const Cadena& other) const;

  /**
   * @brief Lee una cadena desde un flujo.
   * @param in Flujo de entrada.
   * @param cadena Cadena que recibirá el contenido leído.
   * @return El flujo de entrada recibido.
   */
  friend std::istream& operator>>(std::istream& in, Cadena& cadena);

  /**
   * @brief Escribe una cadena en un flujo.
   * @param out Flujo de salida.
   * @param cadena Cadena que se desea escribir.
   * @return El flujo de salida recibido.
   */
  friend std::ostream& operator<<(std::ostream& out, const Cadena& cadena);

 private:
 // Secuencia de símbolos que representa la cadena.
  std::string symbols_;
  // Alfabeto asociado a la cadena.
  Alfabeto alfabeto_;
};

#endif