#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function Prototypes
void displayMainMenu();
void displayInstructions();
void playWarmupRound(char playerName[]);
void playChallengeRound(char playerName[]);
void exitGame();

// Main Function
int main() {
    char choice;
    char playerName[20];

    while (1) {
        displayMainMenu(); // Show the main menu
        printf("\t\t\t\tEnter your choice: ");
        scanf(" %c", &choice);
        choice = toupper(choice);

        switch (choice) {
            case 'S': // Start the game
                printf("\n\n\t\t\t\tEnter your name: ");
                scanf("%s", playerName);
                printf("\n\t\t\t\t*********** Welcome, %s, to the Quiz Game! ***********\n", playerName);
                displayInstructions();
                playWarmupRound(playerName); // Start the warmup round
                break;

            case 'Q': // Quit the game
                exitGame();
                break;

            default: // Invalid input
                printf("\nInvalid choice! Please enter 'S' to start or 'Q' to quit.\n\n");
                break;
        }
    }

    return 0;
}

// Function to display the main menu
void displayMainMenu() {
    printf("\n\n\t\t\t\t     << QUIZ GAMING >>\n");
    printf("\t\t\t\t***************************************\n");
    printf("\t\t\t\t\t       WELCOME\n");
    printf("\t\t\t\t\t         TO\n");
    printf("\t\t\t\t\t      QUIZ GAME\n");
    printf("\t\t\t\t***************************************\n");
    printf("\t\t\t\t >> Press S to start the game\n");
    printf("\t\t\t\t >> Press Q to quit the game\n");
    printf("\t\t\t\t***************************************\n");
}

// Function to display instructions
void displayInstructions() {
    printf("\n\t\t\t\t************** INSTRUCTIONS **************\n");
    printf("\t\t\t\t>> The game has two rounds: Warmup Round and Challenge Round.\n");
    printf("\t\t\t\t>> In the Warmup Round, answer 3 questions. Get at least 2 correct to proceed.\n");
    printf("\t\t\t\t>> In the Challenge Round, answer 10 questions. Each correct answer awards 10 points.\n");
    printf("\t\t\t\t>> Answer questions by typing A, B, C, or D.\n");
    printf("\t\t\t\t>> No negative marking for incorrect answers.\n");
    printf("\t\t\t\t>> Your final score determines whether you win or lose.\n");
    printf("\t\t\t\t*******************************************\n");
}

// Function to play the warmup round
void playWarmupRound(char playerName[]) {
    int correctAnswers = 0;
    char answer;

    printf("\n\t\t\t\t************** WARMUP ROUND **************\n");

    // Question 1
    printf("\n1. What is the time complexity of a binary search algorithm?\n");
    printf("   A) O(n)  B) O(log n)   C) O(n log n)  D) O(1)\n");
    printf("Your answer: ");
    scanf(" %c", &answer);
    answer = toupper(answer);
    if (answer == 'B') {
        printf("Correct!\n");
        correctAnswers++;
    } else {
        printf("Wrong! Correct answer: B) O(log n)\n");
    }

    // Question 2
    printf("\n2. Which HTTP status code indicates a successful request?\n");
    printf("   A) 200  B) 404  C) 500  D) 301\n");
    printf("Your answer: ");
    scanf(" %c", &answer);
    answer = toupper(answer);
    if (answer == 'A') {
        printf("Correct!\n");
        correctAnswers++;
    } else {
        printf("Wrong! Correct answer: A) 200\n");
    }

    // Question 3
    printf("\n3. What data structure is used for Breadth-First Search (BFS) in a graph?\n");
    printf("   A) Stack  B) Queue  C) Priority Queue  D) Linked List\n");
    printf("Your answer: ");
    scanf(" %c", &answer);
    answer = toupper(answer);
    if (answer == 'B') {
        printf("Correct!\n");
        correctAnswers++;
    } else {
        printf("Wrong! Correct answer: B) Queue\n");
    }

    if (correctAnswers >= 2) {
        printf("\nCongratulations, %s! You passed the Warmup Round.\n", playerName);
        playChallengeRound(playerName); // Proceed to the Challenge Round
    } else {
        printf("\nSorry, you did not pass the Warmup Round. Better luck next time!\n");
    }
}

// Function to play the challenge round
void playChallengeRound(char playerName[]) {
    int score = 0;
    char answer;

    printf("\n************** CHALLENGE ROUND **************\n");

    // List of questions and answers
    char *questions[] = {
        "1. Which library is commonly used for deep learning in Python?\n"
        "   A) NumPy  B) TensorFlow  C) pandas  D) Matplotlib\n",

        "2. Which of the following is a backend framework?\n"
        "   A) React.js  B) Vue.js  C) Django  D) Angular\n",

        "3. Which of the following is not a valid keyword in C?\n"
        "   A) typedef  B) void  C) goto  D) reference\n",

        "4. What is the purpose of the finally block in Java?\n"
        "   A) Execute cleanup code  B) Handle exceptions\n"
        "   C) Execute on exception  D) Terminate the program\n",

        "5. Which of the following is an unsupervised learning algorithm?\n"
        "   A) Linear Regression  B) Decision Trees\n"
        "   C) K-Means Clustering  D) Random Forest\n",

        "6. What does the <meta charset=UTF-8> tag do in HTML?\n"
        "   A) Specify character encoding  B) Link CSS\n"
        "   C) Optimize SEO  D) Embed metadata\n",

        "7. Which command checks the status of a Git repository?\n"
        "   A) git log  B) git status  C) git fetch  D) git push\n",

        "8. What is the purpose of a hash table?\n"
        "   A) Store data hierarchically  B) Implement stacks\n"
        "   C) Constant time lookup  D) Sort efficiently\n",

        "9. Which HTTP method sends data to a server?\n"
        "   A) GET  B) POST  C) DELETE  D) PUT\n",

        "10. What is the main purpose of React.js?\n"
        "   A) Server-side scripting  B) Managing UI components\n"
        "   C) Database management  D) Backend development\n"
    };
    char answers[] = {'B', 'C', 'D', 'A', 'C', 'A', 'B', 'C', 'B', 'B'};

    // Loop through questions
    for (int i = 0; i < 10; i++) {
        printf("\n%s", questions[i]);
        printf("Your answer: ");
        scanf(" %c", &answer);
        answer = toupper(answer);

        if (answer == answers[i]) {
            printf("Correct!\n");
            score += 10;
        } else {
            printf("Wrong! Correct answer: %c\n", answers[i]);
        }
    }

    // Final score
    printf("\nYour final score: %d\n", score);
    if (score >= 70) {
        printf("\nCongratulations, %s! You won the game!\n", playerName);
    } else {
        printf("\nSorry, %s, you didn't win. Better luck next time!\n", playerName);
    }
}

// Function to exit the game
void exitGame() {
    printf("\nExiting the game. Thank you for playing!\n");
    exit(0);
}