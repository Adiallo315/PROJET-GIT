#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

// Fonction de callback pour afficher les résultats de la requête SELECT
int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main() {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    // Ouverture de la base de données (elle sera créée si elle n'existe pas)
    rc = sqlite3_open("ma_base_de_donnees.db", &db);

    if (rc) {
        fprintf(stderr, "Impossible d'ouvrir la base de données: %s\n", sqlite3_errmsg(db));
        return rc;
    } else {
        fprintf(stdout, "Base de données ouverte avec succès\n");
    }

    // Création d'une table
    char *sql_create_table = "CREATE TABLE IF NOT EXISTS Utilisateurs("
                             "ID INT PRIMARY KEY     NOT NULL,"
                             "NOM           TEXT    NOT NULL,"
                             "AGE           INT     NOT NULL);";

    rc = sqlite3_exec(db, sql_create_table, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Erreur lors de la création de la table: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Table créée avec succès\n");
    }

    // Insertion de données
    char *sql_insert_data = "INSERT INTO Utilisateurs (ID, NOM, AGE) VALUES (1, 'John Doe', 25);"
                            "INSERT INTO Utilisateurs (ID, NOM, AGE) VALUES (2, 'Jane Doe', 30);";

    rc = sqlite3_exec(db, sql_insert_data, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Erreur lors de l'insertion de données: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Données insérées avec succès\n");
    }

    // Sélection des données
    char *sql_select_data = "SELECT * FROM Utilisateurs;";

    rc = sqlite3_exec(db, sql_select_data, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Erreur lors de la sélection des données: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Données sélectionnées avec succès\n");
    }

    // Fermeture de la base de données
    sqlite3_close(db);

    return 0;
}
