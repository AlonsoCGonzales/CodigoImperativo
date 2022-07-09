#include <stdio.h>

typedef struct{
    char* codAlumno;
    char* codCurso;
    float promedioFinal;
}alumno;

alumno crearA(char* codAlumno,char* codCurso, float promedioFinal){
    alumno nuevo;
    nuevo.codAlumno = codAlumno;
    nuevo.codCurso = codCurso;
    nuevo.promedioFinal = promedioFinal;
    return nuevo;
}

int main() {
    alumno a1,a2,a3,a4,a5,a6;
    
    int i,cont,longitud,alerta;
    float suma, prom,total;
    alerta=cont=suma=prom=total=0;
    
    a1.codAlumno = "EST1001";
    a1.codCurso = "LP710";
    a1.promedioFinal = 14;
    a2.codAlumno = "EST1002";
    a2.codCurso = "LP710";
    a2.promedioFinal = 12;
    a3.codAlumno = "EST1003";
    a3.codCurso = "POO820";
    a3.promedioFinal = 17;
    a4.codAlumno = "EST1001";
    a4.codCurso = "POO820";
    a4.promedioFinal = 13;
    a5.codAlumno = "EST1002";
    a5.codCurso = "POO820";
    a5.promedioFinal = 19;
    a6.codAlumno = "EST1003";
    a6.codCurso = "LP710";
    a6.promedioFinal = 15;
    
    alumno registro[20];
    registro[0] = a1;
    registro[1] = a2;
    registro[2] = a3;
    registro[3] = a4;
    registro[4] = a5;
    registro[5] = a6;
    
    longitud = sizeof(registro) / sizeof(registro[0]);
    
    //Hallar promedio de notas de un alumno (copiar todo y añadirlo al final si se calcular después de añadir un nuevo nodo)
    for(i=0;i<longitud;i++){
        if(registro[i].codAlumno == registro[2].codAlumno){
            suma+=registro[i].promedioFinal;
            total++;
        }
    }
    prom = suma / total;
    printf("Prom.General del alumno %s es %f\n",registro[1].codAlumno,prom);
    
    //Hallar cantidad de alumnos en un curso (copiar todo y añadirlo al final si se calcular después de añadir un nuevo nodo)
    for(i=0;i<longitud;i++){
        if(registro[i].codCurso == registro[4].codCurso){
            cont++;
        }
    }
    printf("El curso %s tiene %d alumnos\n",registro[4].codCurso,cont);
    
    //Ingresar otro nodo (copiar todo si se quiere agregar más, cambiar el a7 segun corresponda al siguiente nodo disponible)
    alumno a7;
    a7=crearA("EST1003","POO820",16);

    for(i=0;i<longitud;i++){
        if(registro[i].codAlumno == a7.codAlumno && registro[i].codCurso == a7.codCurso){
            printf("Ese alumno en ese curso ya existe\n");
            alerta++;
        }
    }
    
    if(alerta == 0){
        printf("Proceda manualmente a registrarlo en el siguiente nodo de la lista ...\n");
        registro[6]=a7;
    }else{
        alerta=0;
    }
    
    //Imprime todos los nodos del registro
    for(i=0;i<longitud;i++){
        printf("\nAlumno: %s Curso: %s Promedio:%f\n", registro[i].codAlumno,registro[i].codCurso,registro[i].promedioFinal);
    }

    return 0;
}