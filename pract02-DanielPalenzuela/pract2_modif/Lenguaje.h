// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Daniel Palenzuela Álvarez
// Correo: alu0101140469@ull.edu.es
// Fecha: 22/09/2026
// Archivo Lenguaje.h: definición de la clase Lenguaje.
// Representa exclusivamente un conjunto de cadenas y proporciona las
// operaciones necesarias para gestionar y visualizar dicho conjunto.
// Historial de revisiones
// 22/09/2026 - Creación del código.

#ifndef LENGUAJE_H_
#define LENGUAJE_H_

#include "Cadena.h"

#include <iosfwd>
#include <set>

/**
 * @file Lenguaje.h
 * @brief Declaración de la clase Lenguaje.
 */

/**
 * @class Lenguaje
 * @brief Representa un conjunto de cadenas.
 *
 * Esta clase se limita a representar y gestionar el conjunto de cadenas.
 * Las operaciones de cadena, como prefijos y sufijos, pertenecen a Cadena,
 * Lenguaje representa sus resultados cuando estos son conjuntos de cadenas.
 */
class Lenguaje {
 public:
  /**
   * @brief Construye un lenguaje vacío.
   */
  Lenguaje();

  /**
   * @brief Inserta una cadena en el lenguaje.
   * @param cadena Cadena que se desea insertar.
   */
  void Insertar(const Cadena& cadena);

  /**
   * @brief Comprueba si el lenguaje es vacío.
   * @return true si no contiene cadenas.
   */
  bool EsVacio() const;

  /**
   * @brief Lee un lenguaje desde un flujo.
   * @param in Flujo de entrada.
   * @param lenguaje Lenguaje que recibirá las cadenas.
   * @return El flujo de entrada recibido.
   */
  friend std::istream& operator>>(std::istream& in, Lenguaje& lenguaje);

  /**
   * @brief Escribe un lenguaje en un flujo.
   * @param out Flujo de salida.
   * @param lenguaje Lenguaje que se desea escribir.
   * @return El flujo de salida recibido.
   */
  friend std::ostream& operator<<(std::ostream& out, const Lenguaje& lenguaje);

 private:
 // Conjunto de cadenas que representa el lenguaje.
  std::set<Cadena> cadenas_;
};

#endif