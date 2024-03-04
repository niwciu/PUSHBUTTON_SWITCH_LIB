/**
 * @file switch.h
 * @author niwciu (niwciu@gmail.com)
 * @brief 
 * @version 0.0.1
 * @date 2024-03-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#define _SWITCH_H_

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */


#define SWITCH_DEBOUNCE_TIME 100U

    // typedef uint8_t input_state_t;
    // typedef uint16_t PB_timer_t;

    // typedef enum
    // {
    //     TRIGER_ON_PUSH,
    //     TRIGER_ON_RELEASE,
    //     TRIGER_ON_SHORT_PUSH_AND_LONG_PUSH
    // } PB_triger_mode_t;

    // /**
    //  * @brief Enumeration representing the status of pushbutton repetition.
    //  *
    //  * This enumeration defines the possible states of pushbutton repetition,
    //  * including inactive and active states.
    //  */

    /**
     * @brief 
     *

     */
    typedef void (*SWITCH_callback_t)(void);


    // /**
    //  * @brief Enumeration representing the different phases of pushbutton actions.
    //  *
    //  * This enumeration defines the possible phases a pushbutton can go through,
    //  * including the released state, push debouncing, short push phase, long push phase,
    //  * and long push phase without repetition.
    //  */
    // typedef enum
    // {
    //     BUTTON_RELEASED,              /**< Represents the released state of the pushbutton. */
    //     PUSH_DEBOUNCING,              /**< Represents the push debouncing phase. */
    //     SHORT_PUSH_PHASE,             /**< Represents the short push phase. */
    //     LONG_PUSH_PHASE,              /**< Represents the long push phase. */
    //     LONG_PUSH_NO_REPETITION_PHASE /**< Represents the long push phase without repetition. */
    // } SWITCH_state_t;

    /**
     * @brief
     *
     *
     * This structure holds information related to a pushbutton, including its GPIO interface,
     * debounce and repetition timer, repetition flag, and callback functions.
     */
    typedef struct
    {
        // PB_driver_interface_t *GPIO_interface; /**< GPIO interface for the pushbutton. */
        // PB_input_state_t input_state;
        // PB_timer_t deb_rep_timer;                    /**< Debounce and repetition timer. */
        // PB_repetition_flag_t REPETITION_STATUS_FLAG; /**< Repetition flag indicating the current state. */
        // PB_callback_t push_callback;                 /**< Callback function on push action. */
        // PB_callback_t release_callback;              /**< Callback function on release action. */
        // PB_repetition_t repetition;                  /**< Repetition option for the pushbutton. */
        // PB_triger_mode_t triger_mode;
        // PB_state_t pushbutton_state_machine; /**< Current state of the pushbutton state machine. */
    } SWITCH_TypDef;

    typedef const SWITCH_driver_interface_t *(*SWITCH_GPIO_interface_get_callback)(void);

    void init_switch(SWITCH_TypDef *SWITCH,SWITCH_GPIO_interface_get_callback PB_get_driver_interface_adr_callback);

    void check_switch(SWITCH_TypDef *SWITCH);

    void register_switch_on_callback(SWITCH_TypDef *SWITCH, PB_callback_t switch_ON_callback);
    void register_switch_off_callback(SWITCH_TypDef *SWITCH, PB_callback_t switch_OFF_callback);
    
    void dec_switch_deb_rep_timer(SWITCH_TypDef *SWITCH);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* _SWITCH_H_ */