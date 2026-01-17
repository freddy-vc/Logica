#include "textpost.h"
#include "quotepost.h"
#include "photopost.h"
#include "videopost.h"
#include "taggedtextpost.h"
#include "taggedphotopost.h"
#include "taggedvideopost.h"
#include <windows.h>
#include <limits>

int validarEntrada(int min, int max, const std::string& mensaje) {
    int valor;

    while(true){
        std::cout << mensaje;
        std::cin >> valor;

        if (!std::cin.fail() && (valor >= min && valor <= max)) return valor;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        std::cout << "Ingrese un número del " << min << " al " << max << ".\n";
    }
}

Post* crearPublicacion(){
    int opcion;
    std::string content, quote, mediaURL;

     do{
        std::cout << "1. Crear publicación de texto.\n"
            << "2. Crear cita.\n" 
            << "3. Crear publicación con foto.\n"
            << "4. Crear publicación con video.\n"
            << "5. Crear publicación de texto con tag.\n"
            << "6. Crear publicación con foto y tag.\n"
            << "7. Crear publicación con video y tag.\n"
            << "8. Cancelar.\n";

        opcion = validarEntrada(1,8,"¿Qué desea realizar?: ");

        switch (opcion) {
        case 1: {
            
            std::cout << "Ingrese el contenido de la publicación: ";
            std::cin.ignore();
            std::getline(std::cin, content);
            
            return new TextPost(content);
        }
        case 2: {
            
            std::cout << "Ingrese el contenido de la publicación: ";
            std::cin.ignore();
            std::getline(std::cin, content);
            std::cout << "Ingrese la cita de la publicación: ";
            std::cin.ignore();
            std::getline(std::cin, quote);

            return new QuotePost(content, quote);
        }
        case 3: {
            
            std::cout << "Ingrese el contenido de la publicación: ";
            std::cin.ignore();
            std::getline(std::cin, content);
            std::cout << "Ingrese la URL de la foto: ";
            std::cin.ignore();
            std::getline(std::cin, mediaURL);

            return new PhotoPost(content, mediaURL);
        }
        case 4: {
            
            std::cout << "Ingrese el contenido de la publicación: ";
            std::cin.ignore();
            std::getline(std::cin, content);
            std::cout << "Ingrese la URL del video: ";
            std::cin.ignore();
            std::getline(std::cin, mediaURL);

            return new VideoPost(content, mediaURL);
        }
        case 5: {
            
            std::cout << "Ingrese el contenido de la publicación: ";
            std::cin.ignore();
            std::getline(std::cin, content);
            
            return new TaggedTextPost(content);
        }
        case 6: {
            
            std::cout << "Ingrese el contenido de la publicación: ";
            std::cin.ignore();
            std::getline(std::cin, content);
            std::cout << "Ingrese la URL de la foto: ";
            std::cin.ignore();
            std::getline(std::cin, mediaURL);

            return new TaggedPhotoPost(content, mediaURL);
        }
        case 7: {
            
            std::cout << "Ingrese el contenido de la publicación: ";
            std::cin.ignore();
            std::getline(std::cin, content);
            std::cout << "Ingrese la URL del video: ";
            std::cin.ignore();
            std::getline(std::cin, mediaURL);

            return new TaggedVideoPost(content, mediaURL);
        }
        case 8:
            std::cout << "Cancelando operación...\n";
            break;
        
        default:
            std::cout << "Opción incorrecta. Intente nuevamente!\n";
            break;
        }
    }while(opcion != 8);

    return nullptr;
}

void mostrarPublicaciones(std::vector<Post*> posts){
     int opcion;
    std::string content, quote, mediaURL;

     do{
        std::cout << "1. Mostrar publicaciones de texto.\n"
            << "2. Mostrar citas.\n" 
            << "3. Mostrar publicaciones con foto.\n"
            << "4. Mostrar publicaciones con video.\n"
            << "5. Mostrar publicacies de texto con tag.\n"
            << "6. Mostrar publicaciones con foto y tag.\n"
            << "7. Mostrar publicaciones con video y tag.\n"
            << "8. Cancelar.\n";

        opcion = validarEntrada(1,8,"¿Qué desea realizar?: ");

        switch (opcion) {
        case 1: {
            for(Post* p : posts) {
                if(p->getTipo() == 1) {
                    std::cout << p << std::endl;
                }
            }
            break;
        }
        case 2: {
            
            for(Post* p : posts) {
                if(p->getTipo() == 2) {
                    std::cout << p << std::endl;
                }
            }
            break;
        }
        case 3: {
            
            for(Post* p : posts) {
                if(p->getTipo() == 3) {
                    std::cout << p << std::endl;
                }
            }
            break;
        }
        case 4: {
            
            for(Post* p : posts) {
                if(p->getTipo() == 4) {
                    std::cout << p << std::endl;
                }
            }
            break;
        }
        case 5: {
            
           for(Post* p : posts) {
                if(p->getTipo() == 5) {
                    std::cout << p << std::endl;
                }
            }
            break;
        }
        case 6: {
            
            for(Post* p : posts) {
                if(p->getTipo() == 6) {
                    std::cout << p << std::endl;
                }
            }
            break;
        }
        case 7: {
            
            for(Post* p : posts) {
                if(p->getTipo() == 7) {
                    std::cout << p << std::endl;
                }
            }
            break;
        }
        case 8:
            std::cout << "Cancelando operación...\n";
            break;
        
        default:
            std::cout << "Opción incorrecta. Intente nuevamente!\n";
            break;
        }
    }while(opcion != 8);
}

void editarPublicacion(std::vector<Post*> posts){ 
    int index = validarEntrada(0, posts.size() - 1, 
        "Ingrese la posición de la publicación a editar (0-"+ std::to_string(posts.size() - 1 )+"): ");

    int postType = posts[index]->getTipo();

    std::string newContent, newQuote, newMediaURL;

    switch (postType) {
        case 1: {
            TextPost* tp = dynamic_cast<TextPost*>(posts[index]);
            if (tp) {
                std::cout << "Ingrese el contenido de la publicación: ";
                std::cin.ignore();
                std::getline(std::cin, newContent);
                tp->setContent(newContent);
            }
            break;
        }
        case 2: {
            QuotePost* qp = dynamic_cast<QuotePost*>(posts[index]);
            if (qp) {
                std::cout << "Ingrese el contenido de la publicación: ";
                std::cin.ignore();
                std::getline(std::cin, newContent);
                std::cout << "Ingrese la cita de la publicación: ";
                std::getline(std::cin, newQuote);
                qp->setContent(newContent);
                qp->quote = newQuote;
            }
            break;
        }
        case 3: {
            PhotoPost* pp = dynamic_cast<PhotoPost*>(posts[index]);
            if (pp) {
                std::cout << "Ingrese el contenido de la publicación: ";
                std::cin.ignore();
                std::getline(std::cin, newContent);
                std::cout << "Ingrese la URL de la foto: ";
                std::getline(std::cin, newMediaURL);
                pp->setContent(newContent);
                pp->setMediaURL(newMediaURL);
            }
            break;
        }
        case 4: {
            VideoPost* vp = dynamic_cast<VideoPost*>(posts[index]);
            if (vp) {
                std::cout << "Ingrese el contenido de la publicación: ";
                std::cin.ignore();
                std::getline(std::cin, newContent);
                std::cout << "Ingrese la URL del video: ";
                std::getline(std::cin, newMediaURL);
                vp->setContent(newContent);
                vp->setMediaURL(newMediaURL);
            }
            break;
        }
        case 5: {
            TaggedTextPost* ttp = dynamic_cast<TaggedTextPost*>(posts[index]);
            if (ttp) {
                std::cout << "Ingrese el contenido de la publicación: ";
                std::cin.ignore();
                std::getline(std::cin, newContent);
                ttp->setContent(newContent);
            }
            break;
        }
        case 6: {
            TaggedPhotoPost* tpp = dynamic_cast<TaggedPhotoPost*>(posts[index]);
            if (tpp) {
                std::cout << "Ingrese el contenido de la publicación: ";
                std::cin.ignore();
                std::getline(std::cin, newContent);
                std::cout << "Ingrese la URL de la foto: ";
                std::getline(std::cin, newMediaURL);
                tpp->setContent(newContent);
                tpp->setMediaURL(newMediaURL);
            }
            break;
        }
        case 7: {
            TaggedVideoPost* tvp = dynamic_cast<TaggedVideoPost*>(posts[index]);
            if (tvp) {
                std::cout << "Ingrese el contenido de la publicación: ";
                std::cin.ignore();
                std::getline(std::cin, newContent);
                std::cout << "Ingrese la URL del video: ";
                std::getline(std::cin, newMediaURL);
                tvp->setContent(newContent);
                tvp->setMediaURL(newMediaURL);
            }
            break;
        }
        default:
            std::cout << "Tipo de publicación no reconocido.\n";
            break;
    }
}

void agregarLike(std::vector<Post*> posts){
    int index = validarEntrada(0, posts.size() - 1, 
        "Ingrese la posición de la publicación a dar like (0-"+ std::to_string(posts.size() - 1 )+"): ");
    
    posts[index]->like();

    std::cout << "\nLike agregado!\n\n";
}

void agregarComentario(std::vector<Post*> posts){
    int index = validarEntrada(0, posts.size() - 1, 
        "Ingrese la posición de la publicación a agregar el comentario (0-"+ std::to_string(posts.size() - 1 )+"): ");
    
    std::string newComment;

    std::cout << "Ingresa el comentario: ";
    std::cin.ignore();
    std::getline(std::cin, newComment);

    posts[index]->addComment(newComment);

    std::cout << "\nComentario agregado!\n\n";
}

void agregarTag(std::vector<Post*> posts){
    std::vector<int> taggeableIndices;

    std::cout << "Publicaciones taggeables:\n";
    for (size_t i = 0; i < posts.size(); ++i) {
        int tipo = posts[i]->getTipo();
        if (tipo == 5 || tipo == 6 || tipo == 7) {
            taggeableIndices.push_back(i);
            std::cout << "[" << taggeableIndices.size() - 1 << "] Posición " << i << ": ";
            if (tipo == 5) std::cout << "TaggedTextPost";
            else if (tipo == 6) std::cout << "TaggedPhotoPost";
            else if (tipo == 7) std::cout << "TaggedVideoPost";
        }
    }

    if (taggeableIndices.empty()) {
        std::cout << "No hay publicaciones taggeables.\n";
        return;
    }

    int localIndex = validarEntrada(0, taggeableIndices.size() - 1, 
        "Ingrese el índice de la publicación taggeable a agregar el tag: ");

    int globalIndex = taggeableIndices[localIndex];

    std::string newTag;

    std::cout << "Ingresa el tag: ";
    std::cin.ignore();
    std::getline(std::cin, newTag);

    Taggable* taggablePost = dynamic_cast<Taggable*>(posts[globalIndex]);
    if (taggablePost) {
        taggablePost->addTag(newTag);
        std::cout << "\nTag agregado!\n\n";
    } else {
        std::cout << "Error: No se pudo agregar el tag.\n";
    }
}

void eliminarPublicacion(std::vector<Post*>& posts){
    if (posts.empty()) {
        std::cout << "No hay publicaciones para eliminar.\n";
        return;
    }

    int index = validarEntrada(0, posts.size() - 1, 
        "Ingrese la posición de la publicación a eliminar (0-"+ std::to_string(posts.size() - 1 )+"): ");

    delete posts[index];
    posts.erase(posts.begin() + index);

    std::cout << "\nPublicación eliminada!\n\n";
}


int main(){
    SetConsoleOutputCP(CP_UTF8);

    int opcion;
    std::vector<Post*> Posts;

    std::cout << "##################################################" << std::endl;
    std::cout << "#######      Gestión de publicaciones      #######" << std::endl;
    std::cout << "##################################################" << std::endl;

    do{
        std::cout << "Menú:\n"
            << "1. Crear publicación.\n"
            << "2. Mostrar publicaciones según tipo de publicación.\n" 
            << "3. Editar publicación.\n"
            << "4. Agregar like a publicación.\n"
            << "5. Agregar comentario a publicación.\n"
            << "6. Agregar etiqueta a publicación.\n"
            << "7. Eliminar una publicación.\n"
            << "8. Salir.\n";

        opcion = validarEntrada(1,8,"¿Qué desea realizar?: ");

        switch (opcion) {
        case 1:{
            Post* newPost = crearPublicacion();
            if (newPost != nullptr) {
                Posts.push_back(newPost);
                std::cout << "\n¡Publicación creada exitosamente!\n\n";
            }
            break;
        }
        case 2:{
            if (!Posts.empty()){
                mostrarPublicaciones(Posts);
            } else {
                std::cout << "No hay publicaciones para mostrar!\n\n";
            }
            break;
        }
        case 3:
            if (!Posts.empty()){
                editarPublicacion(Posts);
            } else {
                std::cout << "No hay publicaciones para editar!\n\n";
            }
            break;
        case 4:{
            if (!Posts.empty()){
                agregarLike(Posts);
            } else {
                std::cout << "No hay publicaciones para likear!\n\n";
            }
            break;
        }
        case 5:{
            if (!Posts.empty()){
                agregarComentario(Posts);
            } else {
                std::cout << "No hay publicaciones para comentar!\n\n";
            }
            break;
        }
        case 6:{
            agregarTag(Posts);
            break;
        }
        case 7:{
            eliminarPublicacion(Posts);
            break;
        }
        case 8:
            std::cout << "Saliendo del programa...\n";
            break;
        
        default:
            std::cout << "Opción incorrecta. Intente nuevamente!\n";
            break;
        }
    }while(opcion != 8);
    
    return 0;
}