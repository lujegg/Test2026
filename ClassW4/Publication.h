#ifndef Publication_H


#define Publication_H
double calculateCost(int pages, double discountPercent);
double calculateCost(int pages);
double calculateCost(int pages, bool hardcover);
double calculateCost(int pages, bool hardcover, int colorPages);
void printReceipt(int pages, bool hardcover, int colorPages, double cost);
#endif // Publication_H