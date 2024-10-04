#include <stdio.h>
#include <string.h>
#define NUM_ESTUDIANTES 5
#define NUM_ASIGNATURAS 3
#define MAX_NOMBRE 50
void limpiarBuffer() {
    int c;
            while ((c = getchar()) != '\n' && c != EOF) {}}
void ingresarNombres(char estudiantes[NUM_ESTUDIANTES][MAX_NOMBRE]) {
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        printf("Ingrese el nombre del estudiante %d: ", i + 1);
        getchar();  // Limpiar el buffer de entrada
        fgets(estudiantes[i], MAX_NOMBRE, stdin);
        
        // Eliminar el salto de línea al final de la cadena si existe
        size_t len = strlen(estudiantes[i]);
        if (len > 0 && estudiantes[i][len - 1] == '\n') {
            estudiantes[i][len - 1] = '\0';
        }
    }
}
void ingresarNombres(char estudiantes[NUM_ESTUDIANTES][MAX_NOMBRE]) {
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        printf("Ingrese el nombre del estudiante %d: ", i + 1);
        scanf("%s", estudiantes[i]);
    }
}

void ingresarCalificaciones(float calificaciones[NUM_ESTUDIANTES][NUM_ASIGNATURAS], char estudiantes[NUM_ESTUDIANTES][MAX_NOMBRE]) {
    const char *asignaturas[] = {"Calculo", "Biologia", "Electronica"};
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        printf("\nIngrese las calificaciones para %s:\n", estudiantes[i]);
        for (int j = 0; j < NUM_ASIGNATURAS; j++) {
            do {
                printf("Calificacion en %s (0-10): ", asignaturas[j]);
                scanf("%f", &calificaciones[i][j]);
                if (calificaciones[i][j] < 0 || calificaciones[i][j] > 10) {
                    printf("Calificacion invalida. Debe estar entre 0 y 10.\n");
                }
            } while (calificaciones[i][j] < 0 || calificaciones[i][j] > 10);
        }
    }
}

void calcularPromedios(float calificaciones[NUM_ESTUDIANTES][NUM_ASIGNATURAS], float promedioEstudiantes[NUM_ESTUDIANTES], float promedioAsignaturas[NUM_ASIGNATURAS]) {
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        float suma = 0;
        for (int j = 0; j < NUM_ASIGNATURAS; j++) {
            suma += calificaciones[i][j];
        }
        promedioEstudiantes[i] = suma / NUM_ASIGNATURAS;
    }

    for (int j = 0; j < NUM_ASIGNATURAS; j++) {
        float suma = 0;
        for (int i = 0; i < NUM_ESTUDIANTES; i++) {
            suma += calificaciones[i][j];
        }
        promedioAsignaturas[j] = suma / NUM_ESTUDIANTES;
    }
}

void encontrarCalificacionesExtremas(float calificaciones[NUM_ESTUDIANTES][NUM_ASIGNATURAS], float altaEstudiante[NUM_ESTUDIANTES], float bajaEstudiante[NUM_ESTUDIANTES], float altaAsignatura[NUM_ASIGNATURAS], float bajaAsignatura[NUM_ASIGNATURAS]) {
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        altaEstudiante[i] = calificaciones[i][0];
        bajaEstudiante[i] = calificaciones[i][0];
        for (int j = 1; j < NUM_ASIGNATURAS; j++) {
            if (calificaciones[i][j] > altaEstudiante[i]) {
                altaEstudiante[i] = calificaciones[i][j];
            }
            if (calificaciones[i][j] < bajaEstudiante[i]) {
                bajaEstudiante[i] = calificaciones[i][j];
            }
        }
    }

    for (int j = 0; j < NUM_ASIGNATURAS; j++) {
        altaAsignatura[j] = calificaciones[0][j];
        bajaAsignatura[j] = calificaciones[0][j];
        for (int i = 1; i < NUM_ESTUDIANTES; i++) {
            if (calificaciones[i][j] > altaAsignatura[j]) {
                altaAsignatura[j] = calificaciones[i][j];
            }
            if (calificaciones[i][j] < bajaAsignatura[j]) {
                bajaAsignatura[j] = calificaciones[i][j];
            }
        }
    }
}

void contarAprobadosReprobados(float calificaciones[NUM_ESTUDIANTES][NUM_ASIGNATURAS], int aprobados[NUM_ASIGNATURAS], int reprobados[NUM_ASIGNATURAS]) {
    for (int j = 0; j < NUM_ASIGNATURAS; j++) {
        aprobados[j] = 0;
        reprobados[j] = 0;
        for (int i = 0; i < NUM_ESTUDIANTES; i++) {
            if (calificaciones[i][j] >= 6) {
                aprobados[j]++;
            } else {
                reprobados[j]++;
            }
        }
    }
}

void imprimirResultados(char estudiantes[NUM_ESTUDIANTES][MAX_NOMBRE], const char *asignaturas[], float calificaciones[NUM_ESTUDIANTES][NUM_ASIGNATURAS], float promedioEstudiantes[NUM_ESTUDIANTES], float promedioAsignaturas[NUM_ASIGNATURAS], float altaEstudiante[NUM_ESTUDIANTES], float bajaEstudiante[NUM_ESTUDIANTES], float altaAsignatura[NUM_ASIGNATURAS], float bajaAsignatura[NUM_ASIGNATURAS], int aprobados[NUM_ASIGNATURAS], int reprobados[NUM_ASIGNATURAS]) {
    printf("\nCalificaciones por estudiante y asignatura:\n");
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        printf("%s:\n", estudiantes[i]);
        for (int j = 0; j < NUM_ASIGNATURAS; j++) {
            printf("  %s: %.2f\n", asignaturas[j], calificaciones[i][j]);
        }
    }

    printf("\nPromedio de calificaciones por estudiante:\n");
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        printf("%s: %.2f\n", estudiantes[i], promedioEstudiantes[i]);
    }

    printf("\nPromedio de calificaciones por asignatura:\n");
    for (int j = 0; j < NUM_ASIGNATURAS; j++) {
        printf("%s: %.2f\n", asignaturas[j], promedioAsignaturas[j]);
    }

    printf("\nCalificacion mas alta y baja por estudiante:\n");
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        printf("%s - Alta: %.2f, Baja: %.2f\n", estudiantes[i], altaEstudiante[i], bajaEstudiante[i]);
    }

    printf("\nCalificacion mas alta y baja por asignatura:\n");
    for (int j = 0; j < NUM_ASIGNATURAS; j++) {
        printf("%s - Alta: %.2f, Baja: %.2f\n", asignaturas[j], altaAsignatura[j], bajaAsignatura[j]);
    }

    printf("\nNumero de estudiantes aprobados y reprobados por asignatura:\n");
    for (int j = 0; j < NUM_ASIGNATURAS; j++) {
        printf("%s - Aprobados: %d, Reprobados: %d\n", asignaturas[j], aprobados[j], reprobados[j]);
    }
}

int main() {
    float calificaciones[NUM_ESTUDIANTES][NUM_ASIGNATURAS];
    char estudiantes[NUM_ESTUDIANTES][MAX_NOMBRE];
    const char *asignaturas[] = {"Calculo", "Biologia", "Electronica"};
    float promedioEstudiantes[NUM_ESTUDIANTES];
    float promedioAsignaturas[NUM_ASIGNATURAS];
    float altaEstudiante[NUM_ESTUDIANTES], bajaEstudiante[NUM_ESTUDIANTES];
    float altaAsignatura[NUM_ASIGNATURAS], bajaAsignatura[NUM_ASIGNATURAS];
    int aprobados[NUM_ASIGNATURAS], reprobados[NUM_ASIGNATURAS];

    ingresarNombres(estudiantes);
    ingresarCalificaciones(calificaciones, estudiantes);
    calcularPromedios(calificaciones, promedioEstudiantes, promedioAsignaturas);
    encontrarCalificacionesExtremas(calificaciones, altaEstudiante, bajaEstudiante, altaAsignatura, bajaAsignatura);
    contarAprobadosReprobados(calificaciones, aprobados, reprobados);
    imprimirResultados(estudiantes, asignaturas, calificaciones, promedioEstudiantes, promedioAsignaturas, altaEstudiante, bajaEstudiante, altaAsignatura, bajaAsignatura, aprobados, reprobados);

    return 0;
}