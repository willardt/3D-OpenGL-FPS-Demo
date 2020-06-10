#include "ProjectileComponent.h"

#include "../src/Resources/Entities/Entity.h"
#include "../src/Resources/Entities/Components/TransformComponent.h"

ProjectileComponent::ProjectileComponent(std::shared_ptr<Entity> entity, const double duration) :
	Component		( entity ),
	_moving			( false ),
	_duration		( duration ),
	_timer			( duration )
{}

ProjectileComponent::ProjectileComponent(std::shared_ptr<Entity> new_entity, const ProjectileComponent& rhs) :
	Component		( new_entity ),
	_moving			( rhs._moving ),
	_dir			( rhs._dir ),
	_duration		( rhs._duration ),
	_timer			( rhs._duration )
{}

std::shared_ptr<Component> ProjectileComponent::copy(std::shared_ptr<Entity> new_entity) const {
	return std::static_pointer_cast<Component>(std::make_shared<ProjectileComponent>(new_entity, *this));
}

void ProjectileComponent::update() {
	if (_moving) {
		auto transform = _entity->get<TransformComponent>();
		transform->move(_dir);
	}

	if (_timer.update()) {
		_entity->destroy();
	}
}

const int ProjectileComponent::get_type() const {
	return _type;
}

void ProjectileComponent::fire(glm::vec3 dir) {
	_dir = dir;
	_moving = true;
}