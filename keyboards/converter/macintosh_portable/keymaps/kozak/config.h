
#pragma once



/* Override Layer count */
#undef DYNAMIC_KEYMAP_LAYER_COUNT
#define DYNAMIC_KEYMAP_LAYER_COUNT 4

/* Faster tap threshold */
#define TAPPING_TERM 175
#undef PERMISSIVE_HOLD
#undef PREVENT_STUCK_MODIFIERS

/* One-shot timeout */
#define ONESHOT_TIMEOUT 175

/* Disable Autocorrect at startup */
#define AUTOCORRECT_OFF_AT_STARTUP

/* Disable LED power status */
#undef LED_POWER_ON

/* Disable LED diagnostic blinking */
#undef LED_DIAG_BLINK

/* Disable debug output */
#undef DEBUG_ENABLE

/* Enable LED layer status */
#define LED_LAYER_STATUS
