Practica-rc4-SO
===============
Practica rc4 de Sistemas Operativos 
Permite validar los vectores de prueba definidos en el FC6229 (http://tools.ietf.org/html/rfc6229).


-La estrategia era conseguir que con cierta key, se lograra obtener el vector de prueba como salida.
-El problema mas fuerte era como meter los datos de la key de los vectores de prueba para que no se tomaran como ascii si no que se imprimieran directamente en la key. ademas de que fue facil encriptar y desencriptar aunque el programa no muestra el enciptamiento y el desencriptado tiene la funcionalidad solo abria que agregar unos printf.
-La Esctructura es simple esta compuesto de el main, unas funciones llamadas Intercambio,S-BOX,KSA,PRNG las cuales son los componentes del algoritmo RC4.
-La estrategia inicial fue complementada con la solución finalmente propuesta ya que se obtenian resultados que no se querian entoces ademas de buscar que con cierta key se lograran obtener el vector de prueba era pensar que key , que tamaño y en que punto del RC4 era obtenido ese vector de prueba que necesitabamos.
