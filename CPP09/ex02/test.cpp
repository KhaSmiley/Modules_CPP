#include <vector>
#include <utility>
#include <iostream>

void mergePairs(std::vector<std::pair<int, int>>& vec, int debut, int milieu, int fin) {
    std::vector<std::pair<int, int>> temp(fin - debut + 1);
    int i = debut, j = milieu + 1, k = 0;
    
    while (i <= milieu && j <= fin) {
        int max1 = std::max(vec[i].first, vec[i].second);
        int max2 = std::max(vec[j].first, vec[j].second);
        
        if (max1 <= max2) {
            temp[k] = vec[i];
            i++;
        } else {
            temp[k] = vec[j];
            j++;
        }
        k++;
    }
    
    while (i <= milieu) {
        temp[k] = vec[i];
        i++;
        k++;
    }
    
    while (j <= fin) {
        temp[k] = vec[j];
        j++;
        k++;
    }
    
    for (i = 0; i < k; i++) {
        vec[debut + i] = temp[i];
    }
}

void triPairesRecursif(std::vector<std::pair<int, int>>& vec, int debut, int fin) {
    if (debut < fin) {
        int milieu = debut + (fin - debut) / 2;
        
        // Tri récursif des deux moitiés
        triPairesRecursif(vec, debut, milieu);
        triPairesRecursif(vec, milieu + 1, fin);
        
        // Fusion des deux moitiés triées
        mergePairs(vec, debut, milieu, fin);
    }
}

// Fonction wrapper pour faciliter l'utilisation
void triPaires(std::vector<std::pair<int, int>>& vec) {
    if (vec.empty()) return;
    triPairesRecursif(vec, 0, vec.size() - 1);
}

int main()
{
    std::vector<std::pair<int, int>> vec = {{3, 5}, {1, 8}, {4, 2}, {7, 1}};
    triPaires(vec);
    std::vector<std::pair<int, int>>::iterator it = vec.begin();
    for (; it != vec.end(); it++) {
        std::cout << it->first << " " << it->second << std::endl;
    }
}