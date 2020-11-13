#pragma once 

namespace test 
{

    class Test
    {
    private:
        /* data */
    public:
        Test(){}
        virtual ~Test(){}

        virtual void OnUpdate( float deltaTime) {}
        virtual void OnRender(){ }
        virtual void OnImGuiRender() {}
    };
    
    


}