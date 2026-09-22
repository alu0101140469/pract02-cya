// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Daniel Palenzuela Álvarez
// Correo: alu0101140469@ull.edu.es
// Fecha: 22/09/2026
// Archivo p02_strings.cc: programa cliente.
// Lee cada línea del fichero de entrada como una cadena seguida de su
// alfabeto y aplica al elemento correspondiente la operación indicada por opcode.
// Historial de revisiones
// 22/09/2026 - Creación del código.

#include "Alfabeto.h"
#include "Cadena.h"
#include "Lenguaje.h"

#include <fstream>
#include <iostream>
#include <string>

namespace {

/**
 * @brief Muestra el modo de empleo del programa.
 * @param program_name Nombre del programa.
 * @param out Flujo de salida.
 */
void MostrarUso(const char* program_name, std::ostream& out) {
  out << "Modo de empleo: " << program_name
      << " filein.txt fileout.txt opcode\n";
  out << "Pruebe '" << program_name
      << " --help' para más información.\n";
}

/**
 * @brief Muestra la ayuda del programa.
 * @param program_name Nombre del programa.
 * @param out Flujo de salida.
 */
void MostrarAyuda(const char* program_name, std::ostream& out) {
  out << "Uso: " << program_name
      << " filein.txt fileout.txt opcode\n\n";

  out << "El fichero de entrada contiene una cadena y su alfabeto en cada línea.\n";
  out << "Formato: cadena alfabeto\n\n";

  out << "Ejemplo:\n";
  out << "  abbab ab\n";
  out << "  6793836 123456789\n";
  out << "  hola ahlo\n\n";

  out << "Códigos de operación:\n";
  out << "  1  Alfabeto\n";
  out << "  2  Longitud\n";
  out << "  3  Inversa\n";
  out << "  4  Prefijos\n";
  out << "  5  Sufijos\n";
  out << "  6  Validación\n\n";

  out << "La cadena vacía se representa con &.\n";
}

/**
 * @brief Comprueba si un opcode es válido.
 * @param opcode Código de operación.
 * @return true si el opcode está entre 1 y 6.
 */
bool EsOpcodeValido(const int opcode) {
  return opcode >= 1 && opcode <= 6;
}

/**
 * @brief Aplica la operación indicada por opcode a la cadena y su alfabeto.
 * @param opcode Código de operación.
 * @param cadena Cadena sobre la que se aplica la operación.
 * @param alfabeto Alfabeto asociado a la cadena.
 * @param out Flujo de salida donde se escribe el resultado.
 */
void AplicarOperacion(const int opcode, const Cadena& cadena,
                      const Alfabeto& alfabeto, std::ostream& out) {
  switch (opcode) {
    case 1:
      out << cadena << ": " << alfabeto;
      break;

    case 2:
      out << cadena.Longitud();
      break;

    case 3:
      out << cadena << " -> " << cadena.Inversa();
      break;

    case 4:
      out << cadena.Prefijos();
      break;

    case 5:
      out << cadena.Sufijos();
      break;

    case 6:
      out << (cadena.EsValida() ? "OK" : "ERROR");
      break;

    default:
      break;
  }

  out << '\n';
}

}

/**
 * @brief Punto de entrada del programa cliente de la práctica.
 * @param argc Número de argumentos de línea de comandos.
 * @param argv Argumentos de línea de comandos.
 * @return 0 si finaliza correctamente; 1 en caso de error.
 */
int main(int argc, char* argv[]) {
    // Se comprueba si se solicita la ayuda del programa.
  if (argc == 2 && std::string(argv[1]) == "--help") {
    MostrarAyuda(argv[0], std::cout);
    return 0;
  }

  // Se comprueba si el número de argumentos es correcto.
  if (argc != 4) {
    MostrarUso(argv[0], std::cerr);
    return 1;
  }

  // Se obtienen los nombres de los ficheros de entrada y salida, y el opcode.
  const std::string input_file = argv[1];
  const std::string output_file = argv[2];
  const std::string opcode_text = argv[3];

  int opcode = 0;

  // Se intenta convertir el opcode a un entero y se comprueba su validez.
  try {
    std::size_t position = 0;

    opcode = std::stoi(opcode_text, &position);

    if (position != opcode_text.size()) {
      throw std::invalid_argument("opcode no válido");
    }
  } catch (const std::exception&) {
    std::cerr << "Error: el opcode debe ser un entero entre 1 y 6.\n";
    return 1;
  }

  if (!EsOpcodeValido(opcode)) {
    std::cerr << "Error: el opcode debe estar entre 1 y 6.\n";
    return 1;
  }

  std::ifstream input(input_file);

  // Se comprueba si se pudo abrir el fichero de entrada.
  if (!input) {
    std::cerr << "Error: no se pudo abrir el fichero de entrada '"
              << input_file << "'.\n";
    return 1;
  }

  std::ofstream output(output_file);

  // Se comprueba si se pudo abrir el fichero de salida.
  if (!output) {
    std::cerr << "Error: no se pudo abrir el fichero de salida '"
              << output_file << "'.\n";
    return 1;
  }

  std::string cadena_texto;
  std::string alfabeto_texto;

  // Se leen las cadenas y sus alfabetos del fichero de entrada y se aplican las operaciones.
  while (input >> cadena_texto >> alfabeto_texto) {
    const Alfabeto alfabeto(alfabeto_texto);
    const Cadena cadena(cadena_texto, alfabeto);

    AplicarOperacion(opcode, cadena, alfabeto, output);
  }

  // Se comprueba si se ha llegado al final del fichero de entrada.
  if (!input.eof()) {
    std::cerr << "Error: formato incorrecto en el fichero de entrada.\n";
    return 1;
  }

  return 0;
}