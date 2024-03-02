#ifndef _KEYBOARD_IT_H_
#define _KEYBOARD_IT_H_

#ifdef __cplusplus
 extern "C" {
#endif

void init_keyboard(void);
void check_keyboard(void);
void update_button_timers (void);


#ifdef __cplusplus
}
#endif

#endif /* _KEYBOARD_IT_H_ */