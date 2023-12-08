#include <iostream>
#include <vector>
#include <time.h>
#include <chrono>
#include <thread>


void afficherTableau(const std::vector<std::string>& tableau) {
    for (const auto& element : tableau) {
        std::cout << element << std::endl;
    }
}

void changerPosition(int index, std::vector<int>& tableau) {
    int temp = tableau[index];
    int aleatoire = rand() % tableau.size();
    while (aleatoire == index) {
        aleatoire = rand() % tableau.size();
    }
    tableau[index] = tableau[aleatoire];
    tableau[aleatoire] = temp;
}

int nombreDevine() {
    std::cout << "Pour decouvrir la solution, entrez un nombre entre 1 et 100 et essayez de deviner le nombre magique" << std::endl;
    int x;
    int entierAleatoire = rand() % 100 + 1;
    do {
        std::cin >> x;
        x > entierAleatoire ? std::cout << " plus bas " : std::cout << " plus haut ";
    } while (x != entierAleatoire); // répéter la lecture de l'utilisateur jusqu'à ce qu'il entre le bon nombre
    std::cout << "Correct ! Vous avez deviné le nombre magique : " << entierAleatoire << std::endl;
    return x;
}

int transformer(int nombreMagique) {
    int x = nombreMagique > 30 ? nombreMagique / 10 : nombreMagique;
    return x;
}

// rechercher un élément dans un tableau
int trouver(std::vector<std::string>& tableau, int nombreMagique) {
    int indexDeLElement;
    int index = 0;
    while (index != tableau.size()) {
        if (index == nombreMagique) {
            indexDeLElement = index;
        }
        index++;
    }

    // générer un nombre aléatoire
    int entierAleatoire = rand() % 100 + 1;
    while (entierAleatoire != nombreMagique) {
        index = 0;
        while (index != tableau.size()) {
            if (index == nombreMagique) {
                indexDeLElement = index;
            }
            index++;
        }
        entierAleatoire = rand() % 100 + 1;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return indexDeLElement;
}

int main() {
    srand((unsigned)time(NULL));

    // créer un tableau rempli de 30 solutionss sur le changement climatique
    std::vector<std::string> solutionsChangementClimatique = {
        "Augmenter l'utilisation de sources d'énergie renouvelables telles que le solaire, l'éolien et l'hydroélectricité.",
        "Mettre en place et appliquer des normes strictes d'efficacité énergétique pour les bâtiments, les appareils et les processus industriels.",
        "Lancer des programmes de reboisement à grande échelle pour planter des arbres et restaurer les forêts.",
        "Encourager l'utilisation de véhicules électriques, des transports en commun et du vélo.",
        "Investir dans la recherche et le développement de technologies de capture et de stockage du dioxyde de carbone.",
        "Promouvoir des pratiques agricoles durables pour réduire la déforestation et limiter l'utilisation d'engrais chimiques.",
        "Mettre en œuvre des stratégies complètes de gestion des déchets pour réduire les émissions des décharges et promouvoir le recyclage et le compostage.",
        "Sensibiliser à propos du changement climatique grâce à des campagnes éducatives.",
        "Développer et moderniser les infrastructures en tenant compte de la résilience climatique.",
        "Favoriser la collaboration et les accords mondiaux pour aborder le changement climatique à l'échelle internationale.",
        "Mettre en place des mécanismes de tarification du carbone tels que des taxes sur le carbone ou des systèmes de plafonnement et d'échange.",
        "Fournir des incitations financières aux propriétaires terriens privés pour qu'ils s'engagent dans des efforts de reboisement et de gestion durable des terres.",
        "Appliquer et améliorer les normes de construction écologiques pour promouvoir des pratiques de construction économes en énergie et respectueuses de l'environnement.",
        "Augmenter le financement de la recherche et du développement de technologies propres et durables.",
        "Soutenir les initiatives communautaires axées sur l'adaptation aux impacts du changement climatique au niveau local.",
        "Promouvoir une économie circulaire en encourageant le recyclage et la réutilisation des produits pour minimiser les déchets.",
        "Encourager un passage vers des régimes alimentaires à base de plantes pour réduire l'impact environnemental de l'élevage.",
        "Fournir des incitations financières et des subventions aux entreprises et aux particuliers investissant dans les énergies renouvelables.",
        "Investir dans le développement et la promotion de variétés de cultures plus résilientes aux conditions climatiques changeantes.",
        "Mettre à niveau les infrastructures énergétiques avec des réseaux intelligents pour améliorer l'efficacité et intégrer mieux les sources d'énergie renouvelable.",
        "Encourager les institutions financières à privilégier les investissements dans des projets écologiquement durables.",
        "Mettre en œuvre des mesures de protection et de restauration des écosystèmes marins, y compris la réduction de la pollution plastique.",
        "Introduire des étiquettes sur les produits indiquant leur empreinte carbone, permettant aux consommateurs de faire des choix écologiques.",
        "Intégrer l'éducation sur le changement climatique dans les programmes scolaires pour assurer que les futures générations soient bien informées.",
        "Soutenir la production alimentaire locale et durable pour réduire l'empreinte carbone associée au transport à longue distance.",
        "Planifier et concevoir des villes en mettant l'accent sur la durabilité, y compris des espaces verts, des transports publics efficaces et des bâtiments économes en énergie.",
        "Fournir une formation aux agriculteurs sur les pratiques agricoles intelligentes face au climat qui renforcent la résilience.",
        "Investir dans la recherche scientifique pour découvrir des solutions nouvelles et innovantes pour atténuer et s'adapter au changement climatique.",
        "Fournir une assistance financière et technique aux nations en développement vulnérables aux impacts du changement climatique.",
        "Développer et promouvoir des outils permettant aux individus de calculer et de réduire leur empreinte carbone, encourageant la responsabilité personnelle."
    };

    // Afficher les informations pour un index spécifique aleatoire (par exemple, l'index 5)
    int indexSpecifique = trouver(solutionsChangementClimatique, transformer(nombreDevine()));
    std::cout << solutionsChangementClimatique[indexSpecifique] << std::endl;
    std::cout << "Fin du programme !";
    return 0;
}
