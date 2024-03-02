/**
 * @file pushbutton_switch.h
 * @author niwciu (niwciu@gmail.com)
 * @brief Library providing an interface for pushbutton switches with debouncing and repetition functionality.
 * @version 0.0.1
 * @date 2024-02-26
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef _PUSHBUTTON_SWITCH_H_
#define _PUSHBUTTON_SWITCH_H_

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
#include "pushbutton_switch_interface.h"

/** @brief Time duration for pushbutton debounce in milliseconds. */
#define PUSHBUTTON_DEBOUNCE_TIME 200U

/** @brief Time duration for the first repetition of a pushbutton press in milliseconds. */
#define PUSHBUTTON_FIRST_REPETITION_TIME 1000U

/** @brief Time duration for continuous repetition of a pushbutton press in milliseconds. */
#define PUSHBUTTON_CONTINUOUS_REPETITION_TIME 500U

/** @brief Time duration for splitting short push and long push in milliseconds. */
#define PUSHBUTTON_SHORT_PUSH_TIME_MAX 1000U

    typedef uint8_t input_state_t;
    typedef uint16_t PB_timer_t;

    typedef enum
    {
        TRIGER_ON_PUSH,
        TRIGER_ON_RELEASE,
        TRIGER_ON_SHORT_PUSH_AND_LONG_PUSH
    } PB_triger_mode_t;

    /**
     * @brief Enumeration representing the status of pushbutton repetition.
     *
     * This enumeration defines the possible states of pushbutton repetition,
     * including inactive and active states.
     */
    typedef enum
    {
        REPETITION_INACTIVE, /**< Represents the inactive state of pushbutton repetition. */
        REPETITION_ACTIVE    /**< Represents the active state of pushbutton repetition. */
    } PB_repetition_flag_t;

    /**
     * @brief Callback function pointer type for pushbutton events.
     *
     * This type defines the function signature for callback functions to be associated
     * with pushbutton events.
     */
    typedef void (*PB_callback_t)(void);

    /**
     * @brief Enumeration for pushbutton repetition options.
     *
     * This enumeration defines options for controlling pushbutton repetition behavior.
     */
    typedef enum
    {
        REPETITION_ON,  /**< Enables pushbutton repetition. */
        REPETITION_OFF, /**< Disables pushbutton repetition. */
    } PB_repetition_t;

    /**
     * @brief Enumeration representing the different phases of pushbutton actions.
     *
     * This enumeration defines the possible phases a pushbutton can go through,
     * including the released state, push debouncing, short push phase, long push phase,
     * and long push phase without repetition.
     */
    typedef enum
    {
        BUTTON_RELEASED,              /**< Represents the released state of the pushbutton. */
        PUSH_DEBOUNCING,              /**< Represents the push debouncing phase. */
        SHORT_PUSH_PHASE,             /**< Represents the short push phase. */
        LONG_PUSH_PHASE,              /**< Represents the long push phase. */
        LONG_PUSH_NO_REPETITION_PHASE /**< Represents the long push phase without repetition. */
    } PB_state_t;

    /**
     * @brief
     *
     *
     * This structure holds information related to a pushbutton, including its GPIO interface,
     * debounce and repetition timer, repetition flag, and callback functions.
     */
    typedef struct
    {
        PB_driver_interface_t *GPIO_interface; /**< GPIO interface for the pushbutton. */
        PB_input_state_t input_state;
        PB_timer_t deb_rep_timer;                    /**< Debounce and repetition timer. */
        PB_repetition_flag_t REPETITION_STATUS_FLAG; /**< Repetition flag indicating the current state. */
        PB_callback_t push_callback;                 /**< Callback function on push action. */
        PB_callback_t release_callback;              /**< Callback function on release action. */
        PB_repetition_t repetition;                  /**< Repetition option for the pushbutton. */
        PB_triger_mode_t triger_mode;
        PB_state_t pushbutton_state_machine; /**< Current state of the pushbutton state machine. */
    } PUSHBUTTON_TypDef;

    typedef const PB_driver_interface_t *(*PB_GPIO_interface_get_callback)(void);

    void init_pushbutton(PUSHBUTTON_TypDef *BUTTON,
                         const PB_repetition_t PB_repetition_mode,
                         PB_triger_mode_t PB_triger_mode,
                         PB_GPIO_interface_get_callback PB_get_driver_interface_adr_callback);

    void check_pushbutton(PUSHBUTTON_TypDef *BUTTON);
    void check_button_push(PUSHBUTTON_TypDef *BUTTON);
    void check_button_release(PUSHBUTTON_TypDef *BUTTON);
    void check_button_short_push_long_push(PUSHBUTTON_TypDef *BUTTON);

    void register_button_push_callback(PUSHBUTTON_TypDef *BUTTON, PB_callback_t callback_on_push);
    void register_button_release_callback(PUSHBUTTON_TypDef *BUTTON, PB_callback_t callback_on_button_release);
    void register_button_short_push_long_push_callbacks(PUSHBUTTON_TypDef *BUTTON, PB_callback_t callback_on_short_push, PB_callback_t callback_on_long_push);

    void enable_pusbutton_repetition(PUSHBUTTON_TypDef *BUTTON);
    void disable_pusbutton_repetition(PUSHBUTTON_TypDef *BUTTON);

    void dec_pushbutton_deb_rep_timer(PUSHBUTTON_TypDef *BUTTON);

    /*
     * functionality to be implemented in the future for singals
     *
     */

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* _PUSHBUTTON_SWITCH_H_ */