
#pragma once

// Override Layer count
#undef DYNAMIC_KEYMAP_LAYER_COUNT
#define DYNAMIC_KEYMAP_LAYER_COUNT 4

// Faster tap threshold
#define TAPPING_TERM 160
#undef PERMISSIVE_HOLD
#undef PREVENT_STUCK_MODIFIERS

// One-shot timeout
#define ONESHOT_TIMEOUT 500

// Disable Autocorrect at startup
#define AUTOCORRECT_OFF_AT_STARTUP
