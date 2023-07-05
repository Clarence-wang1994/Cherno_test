// #include <memory>
// #include <iostream>

// class Entity{
//     public:
//         Entity(){

//         }

//         ~Entity(){
//             std::cout << "destory the Entity" << std::endl;
//         }

//         void PrintEntity(){

//         }

// };

// int main(){
//     {
//         std::shared_ptr<Entity> entity(new Entity());
        
//         std::cout << entity.use_count() << std::endl;
//         {
//             // std::unique_ptr<Entity> entity = std::make_unique<Entity>();
//             // std::unique_ptr<Entity> tmp = entity;
//             std::shared_ptr<Entity> tmp = entity;
//             std::cout << entity.use_count() << std::endl;
//             std::weak_ptr<Entity> ptr_Entity = tmp;
//             std::cout << entity.use_count() << std::endl;
//         }
//     }

   

//     std::cin.get();
// }

