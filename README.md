# EventHandler

Reinterpretación de la clase EventHandler de C# para usarla en proyectos con Arduino y ESP.

## Instalación

Utilizando la consola de tu preferencia, dirigete a la ruta de las librerias de arduino de tu instalacion. Por ejemplo:

``` bash
cd P:\Arduino\libraries
```

Una vez dentro del directorio solo basta con clonar el proyecto de la libreria en la versión que gustes.

``` bash
git clone git@gitlab.com:arduinolibraries/EventHandler.git .
```

Esto creara el directorio EventHandler de la libreria junto con los archivos de documentación y los ejemplos.

## Seleccion de versión

Por defecto, luego de instalar desde el repositorio, la versión seleccionada es la última vigente en master. Si quiere puede seleccionar otra version en cualquier momento utilizando los comandos git checkout y haciendo referencia a la versión que desee.

``` bash
git checkout tag/<versión>
```

Puede ver un listado de las versiones disponibles por medio del siguiente comando

``` bash
git fetch --tags
```

## Actualización

Para actualizar a la última versión solo es necesario ejecutar un simple pull

``` bash
git pull
```

Luego podra seleccionar la última versión siguiendo los pasos de Selección de versión

## Uso

La libreria incluye una clase EventHandler instanciable. Durante la declaración de la instancia se debe definir los argumentos que utilizaran los callbacks que se deseen manejar como eventos. Por ejemplo:

``` c++
EventHandler<bool, int> pulsadorActivado;
```

En el ejemplo pulsadorActivado es una instancia de EventHandler que permite almacenar varios punteros de función que cumplen con la misma firma.

``` c++
pulsadorActivado.Add( funcUno );
pulsadorActivado.Add( funcDos );

void funcUno(bool a, int b){
    //hace alguna cosa
}

void funcDos(bool aa, int bb){
    //hace otra cosa
}
```

Para invocar los eventos que almacenados en la instancia de EventHandler, se debe llamar al metodo Invoke. Invoke iterara sobre el vector de callbacks y ejecutara cada función en el orden en que fueron agregados. El metodo Invoke recibirá los argumentos definidos durante la declaración de la isntancia.

``` c++
pulsadorActivado.Invoke(true, 123);
```

Siguiendo el ejemplo, al invocar pulsadorActivado con los parametros true y 123. Se ejecutaran las funciones funcUno y funcDos ambas con los mismos valores.

## Links

- [Cambios de version](CHANGELOG.md)
- [Repositorio](https://gitlab.com/arduinolibraries/EventHandler/-/tree/master)