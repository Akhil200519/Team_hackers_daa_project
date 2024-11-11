   #include <stdio.h>
#define MAX_COURSES 5
#define MAX_OUTCOMES 5
void inputMatrix(int matrix[MAX_COURSES][MAX_OUTCOMES], int courses, int outcomes) {
    printf("Enter the course articulation matrix:\n");
    for (int i = 0; i < courses; i++) {
        for (int j = 0; j < outcomes; j++) {
            printf("Matrix[%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX_COURSES][MAX_OUTCOMES], int courses, int outcomes) {
    printf("\nCourse Articulation Matrix:\n");
    for (int i = 0; i < courses; i++) {
        for (int j = 0; j < outcomes; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void sortMatrix(int matrix[MAX_COURSES][MAX_OUTCOMES], int courses, int outcomes) {
    int i, j, k, sum_i, sum_j, temp;
    for (i = 0; i < courses - 1; i++) {
        for (j = i + 1; j < courses; j++) {
            sum_i = 0;
            sum_j = 0;
            for (k = 0; k < outcomes; k++) {
                sum_i += matrix[i][k];
                sum_j += matrix[j][k];
            }
            if (sum_i > sum_j) {
                for (k = 0; k < outcomes; k++) {
                    temp = matrix[i][k];
                    matrix[i][k] = matrix[j][k];
                    matrix[j][k] = temp;
                }
            }
        }
    }
}

int searchCourse(int matrix[MAX_COURSES][MAX_OUTCOMES], int courses, int outcomes, int target[MAX_OUTCOMES]) {
    int i, j;
    for (i = 0; i < courses; i++) {
        int found = 1;
        for (j = 0; j < outcomes; j++) {
            if (matrix[i][j] != target[j]) {
                found = 0;
                break;
            }
        }
        if (found) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int courses, outcomes;
    int target[MAX_OUTCOMES];

    printf("Enter the number of courses: ");
    scanf("%d", &courses);
    printf("Enter the number of outcomes: ");
    scanf("%d", &outcomes);

    int matrix[MAX_COURSES][MAX_OUTCOMES];

    inputMatrix(matrix, courses, outcomes);
    
    sortMatrix(matrix, courses, outcomes);
    
    printf("\nSorted ");
    displayMatrix(matrix, courses, outcomes);

    printf("Enter the course articulation to search for:\n");
    for (int i = 0; i < outcomes; i++) {
        printf("Target[%d]: ", i+1);
        scanf("%d", &target[i]);
    }

    int index = searchCourse(matrix, courses, outcomes, target);
    if (index != -1) {
        printf("Course articulation found at index: %d\n", index + 1);
    } else {
        printf("Course articulation not found.\n");
    }

    return 0;
}
