#ifndef COMPONENT
#define COMPONENT

#include <set>

class Component
{
public:
	virtual void Start() = 0;
	virtual void Draw() = 0;
	virtual void Update(float dt) = 0;
};

class Updatable : public Component
{
public:
	//Updatable();

	void StartAll();
	void DrawAll();
	void UpdateAll(float dt);

	void RegisterUpdate(Component* c);

	void Start() override { }
	void Draw() override { }
	void Update(float update) override { }

private:
	std::set<Component*> updatables;
};

#endif