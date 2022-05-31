#include "Component.hpp"

//Updatable::Updatable() { }

void Updatable::StartAll()
{
	for (Component* c : this->updatables)
	{
		c->Start();
	}
}

void Updatable::DrawAll()
{
	for (Component* c : this->updatables)
	{
		c->Draw();
	}
}

void Updatable::UpdateAll(float dt)
{
	for (Component* c : this->updatables)
	{
		c->Update(dt);
	}
}

void Updatable::RegisterUpdate(Component* c)
{
	this->updatables.insert(c);
}