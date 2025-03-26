/* DB.h
 * 
 * Public interface to the specification for your database implementation
 *
 * Please do not modify any code in this file!  We will be testing your code
 * under the assumption that the public interface matches this interface.
 *
 * Author: Gabrielle Phillips, Lara Halawa, Emem Afanide, Andy Tran
 * Lab instructor: RD Ardy
 * Lecture instructor: RD Ardy , Dhara Wagh
 */

#ifndef DB_H
#define DB_H

/*
 * DECLARE AND TYPEDEF HERE THE STRUCTS Table, NeighbourhoodTable, AND PicnicTable
 * WHICH WILL BE FIELDS IN THE STRUCT DataBase BELOW. YOU MAY DECLARE ADDITIONAL
 * STRUCTS AS NEEDED.
 */


/*
 * The INIT_SIZE is only relevant if you are using arrays for your data structures. 
 * If you are using linked lists you will not need it
 */
#define INIT_SIZE 5 

typedef struct {
    unsigned short int tableID;
    char *TableType;
}Entries;

typedef struct {
    unsigned int size;
    unsigned int capacity;
    Entries *arr;
}Table;

typedef struct {
    unsigned int size;
    unsigned int capacity;
    Entries *arr;
}NeighbourhoodTable;



typedef struct {
// holds all the each entry in the .csv file 
// Maybe change bit size to some (later thing to do?)
    unsigned short int TableTypeId; 
    unsigned short int SiteId;
    unsigned short int TableId;
    unsigned short int structuralMaterialId;
    unsigned short int surfaceMaterialId;
    unsigned short neighbhdId;
    char *WardId;
    char *latitude;
    char *longitude;
    char *location;
    char *streetAvenue;
    char *NeighbourhoodName;
}ThingsforTable;

typedef struct {
    unsigned int size;
    unsigned int capacity;
    ThingsforTable *TableTable // array of thingsfortable with entry of tabletable

}PicnicTable;



/*
 * You may change the internal details of the struct below,
 * only keep it typedef'ed to DataBase
 */
typedef struct {
    // You can add anything you see fit here
    Table *tableTypeTable;
    Table *surfaceMaterialTable;
    Table *structuralMaterialTable;
    NeighbourhoodTable *neighborhoodTable;
    PicnicTable *picnicTableTable;
} DataBase;

/* Declare a global DataBase variable*/
/* That should be the only global variable declared*/
/* DB.c should have the definition of this variable*/
extern DataBase *Db;

// his function takes the name of a .csv file as parameter and creates and populates the Database with the corresponding data set information.
void importDB(file name);


// this function takes the name of a .csv file as parameter and creates a .csv file containing the information of the Database. NOTE: the exported .csv file must be exactly the same as the original .csv file from which the Database was created.
void exportDB(file name);


/*
 * Take the name of a member of the picnicTable entry and a value for that member 
 * as parameters and return the number of entries in the picnicTable which have 
 * that value for the memberName.
 * 
 * This is to be implemented for the following members:
 *  1- Table Type
 *  2- Surface Material
 *  3- Structural Material
 *  4- Neighborhood ID
 *  5- Neighborhood Name
 *  6- Ward
 */

int countEntries(char *memberName, char * value);

/*
 * Take the name of a member of the picnicTable entry as an argument 
 * and sort the table in ascending order of the entry values of that member. 
 * The function must be implemented for:
 *   1- Table Type
 *   2- Surface Material
 *   3- Structural Material
 *   4- Neighborhood Name
 *   5- Ward
 */
void sortByMember(char *memberName);

/*
 * Take a tableID, the name of a member of the picnicTable entry and a value for that 
 * member as parameters, and find the entry which has that tableID and 
 * change its memberName value to newValue. 
 * Members that can be modified:
 *  1- Table Type
 *  2- Surface Material
 *  3- Structural Material 
 * If the new value is not found in the existing tables, this value must be added to the 
 * corresponding table.
 */
void editTableEntry(int tableID, char *memberName, char *value);



/*
 * print a listing of picnic tables grouped by neigbourhoods in ascending 
 * alphabetical order.
 */
void reportByNeighbourhood();

/*
 * print a listing of picnic tables grouped by wards in ascending order.
 */
void reportByWard();

/*
 * Frees all dynamic memory associated with each table upon exit. 
 */
void freeDB();


#endif
