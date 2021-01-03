#include <QCoreApplication>
#include <QDir>
#include <QtDebug>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString carpeta = "C:/ActividadQt";
    QDir directorio(carpeta);
    qDebug()<<directorio.absolutePath()<<directorio.exists();

    //Lista de contenido ordenado
    QFileInfoList contenido = directorio.entryInfoList(QDir::Dirs,QDir::Name);

    //Tamaño de la carpeta

    int tamanio = contenido.size();

    //Obtener la ultima carpeta
    QFileInfo ultima_carpeta = contenido.at(tamanio-1);

    //Obtener el nombre de la ultima carpeta
    QString nombre_uc = ultima_carpeta.fileName();
    QString numero_string = nombre_uc.remove(0,7);
    int numero = numero_string.toInt();
    numero++;

    int opc= 0;
    do{
        qDebug()<<"***** Bienvenido ****";
        qDebug()<<" Por favor seleccione una opcion";
        qDebug()<<"1.- Crear una nueva carpeta";
        qDebug()<<"2.- Eliminar los subdirectorios de numero impar";
        qDebug()<<"3.- Renombrar el directorio";
        qDebug()<<"4.- Eliminar archivos .txt pares";
        qDebug()<<"5.- Salir";

        int opc;
        std::cin>>opc;
        switch (opc) {
        case 1:{
            qDebug()<<"  Nueva Carpeta   ";
            QString nueva_carpeta = "Carpeta" + QString::number(numero);
            qDebug()<<nueva_carpeta;
            if(directorio.mkdir(nueva_carpeta)){
                qDebug()<<"Carpeta creada"<<nueva_carpeta;
            }else{
                qWarning()<<"No se ha creado la carpeta";
            }
            directorio.refresh();
        }
            break;
        case 2:{
            qDebug()<<"  Eliminar subdirectorios    ";
            for( int i=1; i<=10; i+=2){
                QString eliminar_carpeta = "Carpeta" + QString::number(i);
                eliminar_carpeta.insert(0, "C:/ActividadQt/");
                qDebug()<<eliminar_carpeta;
                QDir carpEliminar(eliminar_carpeta);
                if(carpEliminar.exists()){
                    qDebug()<<eliminar_carpeta;
                    if(carpEliminar.removeRecursively()){
                        qDebug()<<"Se ha eliminado la carpeta "<<eliminar_carpeta;
                    }else{
                        qWarning()<<"No se ha podido eliminar la carpeta";
                    }
                }


            }
        }
            break;
        case 3:
        {
            qDebug()<<"  Renombrar carperta 2 a directorio 2     ";
            QFileInfo carpeta2 = contenido.at(3);
            QString carpeta_2 = carpeta2.fileName();
            QString name = "Directorio 2";
            if(directorio.rename(carpeta_2,name)){
                qDebug()<<"Se ha cambiado el nombre de *Carpeta 2* a "<<name;
            }else{
                qDebug()<<"No se ha realizado ningun cambio";

            }
        }
            break;
        case 4:
        {
            qDebug()<<"   Eliminar archivos .txt    ";
            qDebug()<<"Listanto carpetas existentes\n";
            QStringList lista = QDir("C:/ActividadQt/").entryList();
            qDebug()<< lista;

            QString carpta= "Directorio 2";
            qDebug()<<"\nIngresando a: "<<carpta;
            if(!directorio.cd(carpta)){
                qWarning()<<"No existe el directorio"<<carpta;
            }else{
                QStringList contenido = directorio.entryList();
                foreach (QString elemento, contenido){
                    qDebug()<< elemento;
                }
                directorio.cdUp();

                qDebug()<<" Eliminado Archivos .txt terminados en numero par";
                for(int i=0; i<=10; i+=2){
                    QString eliminar_archivo = "Archivo" + QString :: number(i);
                    eliminar_archivo.insert(0, "C:/ActividadQt/");
                    qDebug()<<eliminar_archivo;
                    QDir archivoEliminar(eliminar_archivo);
                    if(archivoEliminar.exists()){
                        qDebug()<<eliminar_archivo;
                        if(archivoEliminar.removeRecursively()){
                            qDebug()<<"Se ha eliminado el archivo "<<eliminar_archivo;
                        }else{
                            qWarning()<<" No se ha podido eliminar el archivo ";
                        }
                    }
                }
            }

            QString carpta4 = "Carpeta4";
            qDebug()<<"\nIngresando a "<<carpta4;
            if(!directorio.cd(carpta4)){
                qWarning()<< "No existe el directorio"<<carpta4;
            }else{
                QStringList contenido = directorio.entryList();
                foreach (QString elemento, contenido){
                    qDebug()<<elemento;
                }
                directorio.cdUp();

                qDebug()<<" Eliminado Archivos .txt terminados en numero par";
                for(int i=0; i<=10; i+=2){
                    QString elimina_archivo = "Archivo" + QString::number(i);
                    elimina_archivo.insert(0, "C:/ActividadQt/");
                    qDebug()<<elimina_archivo;
                    QDir archivoEliminar(elimina_archivo);
                    if(archivoEliminar.exists()){
                        qDebug()<<elimina_archivo;
                        if(archivoEliminar.removeRecursively()){
                            qDebug()<<"Se ha eliminado el archivo "<<elimina_archivo;
                        }else{
                            qWarning()<<" No se ha podido eliminar el archivo ";
                        }
                    }

                }
            }
        }
            break;
        }
    }while(opc>=5);
    qDebug()<<"Gracias por usar este programa vuelva pronto";
    return 0;
}
