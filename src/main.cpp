#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>
using namespace geode::prelude;
class $modify(PlayerObject) {
	void updateJump(float delta) {
			float direction = this->m_isUpsideDown ? -1 : 1;
			float size = 1.0;			
			if (this->m_vehicleSize != 1.0) 
				size = 0.85f;
			double& yAccel = this->m_jumpAccel;
			if (fabs(yAccel) > 6)
				this->m_gravity+= 1;
			double n_yAccel = yAccel + (this->m_gravity * delta * direction * -0.5)/size;
			if (!(fabs(yAccel) > 6 && fabs(n_yAccel) > fabs(yAccel)))
				yAccel = n_yAccel;

			if (this->m_isHolding && this->m_hasJustHeld) {
				this->m_hasJustHeld = false;
				this->flipGravity(direction==1.0, true);
			}
		return PlayerObject::updateJump(delta);
	} 
};
