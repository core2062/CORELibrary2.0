/*
 * JoystickCache.h
 *
 *  Created on: Aug 25, 2015
 *      Author: core
 */

#ifndef SRC_CORELIB_JOYSTICKCACHE_H_
#define SRC_CORELIB_JOYSTICKCACHE_H_

#include "WPILib.h"
#include <string>
#include <map>
#include "Constants.h"
namespace CORE{

class JoystickCache{
public:
	enum Metadata {
		RISING = 1,
		FALLING = 2,
		NORMAL = 0
	};
private:
	struct j_key{
		int joystick;
		int channel;
		Metadata type;
	    j_key( int joystick, int channel, Metadata type) : joystick( joystick ), channel(channel), type(type) {}
	};

	typedef std::map<controllerInputs, j_key> j_map;
	typedef std::map<controllerInputs, double> d_cache;
	typedef std::map<controllerInputs, bool> b_cache;

public:
	Joystick joystick1;
	Joystick joystick2;

	j_map axes;
	j_map buttons;

	d_cache cached_axes;
	b_cache cached_button;
	b_cache old_buttons;

	JoystickCache():
			joystick1(0),
			joystick2(1){

	}

	void register_axis (controllerInputs name, int joystick, int axis);

	void register_button(controllerInputs name, int joystick, int button);

	void register_button(controllerInputs name, int joystick, int button, Metadata type);

	void update_cache(void);

	double axis(controllerInputs name);

	bool button(controllerInputs name);

	Joystick& get_joystick(int axis);



};
}
#endif /* SRC_CORELIBRARY_JOYSTICKCACHE_H_ */
