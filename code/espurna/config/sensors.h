//--------------------------------------------------------------------------------
// Custom RF module
// Check http://tinkerman.cat/adding-rf-to-a-non-rf-itead-sonoff/
// Enable support by passing RF_SUPPORT=1 build flag
//--------------------------------------------------------------------------------

#ifndef RF_SUPPORT
#define RF_SUPPORT                  0
#endif

#define RF_PIN                      14
#define RF_CHANNEL                  31
#define RF_DEVICE                   1

//--------------------------------------------------------------------------------
// DHTXX temperature/humidity sensor
// Enable support by passing DHT_SUPPORT=1 build flag
//--------------------------------------------------------------------------------

#ifndef DHT_SUPPORT
#define DHT_SUPPORT                 0
#endif

#define DHT_PIN                     14
#define DHT_UPDATE_INTERVAL         60000
#define DHT_TYPE                    DHT22
#define DHT_TIMING                  11
#define DHT_TEMPERATURE_TOPIC       "temperature"
#define DHT_HUMIDITY_TOPIC          "humidity"

#define HUMIDITY_NORMAL             0
#define HUMIDITY_COMFORTABLE        1
#define HUMIDITY_DRY                2
#define HUMIDITY_WET                3

//--------------------------------------------------------------------------------
// Analog sensor
// Enable support by passing ANALOG_SUPPORT=1 build flag
//--------------------------------------------------------------------------------

#ifndef ANALOG_SUPPORT
#define ANALOG_SUPPORT              0
#endif

#define ANALOG_PIN                  0
#define ANALOG_UPDATE_INTERVAL      60000
#define ANALOG_TOPIC                "analog"

#if ANALOG_SUPPORT
    #undef ADC_VCC_ENABLED
    #define ADC_VCC_ENABLED         0
#endif

//--------------------------------------------------------------------------------
// Counter sensor
// Enable support by passing COUNTER_SUPPORT=1 build flag
//--------------------------------------------------------------------------------

#ifndef COUNTER_SUPPORT
#define COUNTER_SUPPORT             0           // Do not build with counter support by default
#endif

#define COUNTER_PIN                 2           // GPIO to monitor
#define COUNTER_PIN_MODE            INPUT       // INPUT, INPUT_PULLUP
#define COUNTER_INTERRUPT_MODE      RISING      // RISING, FALLING, BOTH
#define COUNTER_UPDATE_INTERVAL     5000        // Update counter every this millis
#define COUNTER_REPORT_EVERY        12          // Report counter every this updates (1 minute)
#define COUNTER_DEBOUNCE            10          // Do not register events within less than 10 millis
#define COUNTER_TOPIC               "counter"   // Default topic for MQTT, API and InfluxDB

//--------------------------------------------------------------------------------
// DS18B20 temperature sensor
// Enable support by passing DS18B20_SUPPORT=1 build flag
//--------------------------------------------------------------------------------

#ifndef DS18B20_SUPPORT
#define DS18B20_SUPPORT             0
#endif

#define DS18B20_PIN                 14
#define DS18B20_UPDATE_INTERVAL     60000
#define DS18B20_TEMPERATURE_TOPIC   "temperature"

//--------------------------------------------------------------------------------
// Custom current sensor
// Check http://tinkerman.cat/your-laundry-is-done/
// Check http://tinkerman.cat/power-monitoring-sonoff-th-adc121/
// Enable support by passing EMON_SUPPORT=1 build flag
//--------------------------------------------------------------------------------

#ifndef EMON_SUPPORT
#define EMON_SUPPORT                0
#endif

#define EMON_ANALOG_PROVIDER        0
#define EMON_ADC121_PROVIDER        1

// If you select EMON_ADC121_PROVIDER you need to enable and configure I2C in general.h
#define EMON_PROVIDER               EMON_ANALOG_PROVIDER

#if EMON_PROVIDER == EMON_ANALOG_PROVIDER
    #define EMON_CURRENT_PIN        0
	#define EMON_ADC_BITS           10
	#define EMON_REFERENCE_VOLTAGE  1.0
    #define EMON_CURRENT_OFFSET     0.25
    #if EMON_SUPPORT
        #undef ADC_VCC_ENABLED
		#define ADC_VCC_ENABLED     0
    #endif
#endif

#if EMON_PROVIDER == EMON_ADC121_PROVIDER
    #define EMON_ADC121_ADDRESS     0x50
	#define EMON_ADC_BITS           12
	#define EMON_REFERENCE_VOLTAGE  3.3
    #define EMON_CURRENT_OFFSET     0.10
#endif

#define EMON_CURRENT_RATIO          30
#define EMON_SAMPLES                1000
#define EMON_INTERVAL               10000
#define EMON_MEASUREMENTS           6
#define EMON_MAINS_VOLTAGE          230
#define EMON_APOWER_TOPIC           "apower"
#define EMON_ENERGY_TOPIC           "energy"
#define EMON_CURRENT_TOPIC          "current"

//--------------------------------------------------------------------------------
// HLW8012 power sensor (Sonoff POW, Espurna H)
// Enable support by passing HLW8012_SUPPORT=1 build flag
//--------------------------------------------------------------------------------

#ifndef HLW8012_SUPPORT
#define HLW8012_SUPPORT             0
#endif

// GPIOs defined in the hardware.h file

#define HLW8012_USE_INTERRUPTS      1
#define HLW8012_SEL_CURRENT         HIGH
#define HLW8012_CURRENT_R           0.001
#define HLW8012_VOLTAGE_R_UP        ( 5 * 470000 ) // Real: 2280k
#define HLW8012_VOLTAGE_R_DOWN      ( 1000 ) // Real 1.009k
#define HLW8012_POWER_TOPIC         "power"
#define HLW8012_CURRENT_TOPIC       "current"
#define HLW8012_VOLTAGE_TOPIC       "voltage"
#define HLW8012_APOWER_TOPIC        "apower"
#define HLW8012_RPOWER_TOPIC        "rpower"
#define HLW8012_PFACTOR_TOPIC       "pfactor"
#define HLW8012_ENERGY_TOPIC        "energy"
#define HLW8012_UPDATE_INTERVAL     5000
#define HLW8012_REPORT_EVERY        12
#define HLW8012_MIN_POWER           5
#define HLW8012_MAX_POWER           2500
#define HLW8012_MIN_CURRENT         0.05
#define HLW8012_MAX_CURRENT         10

//--------------------------------------------------------------------------------
// V9261F power sensor (Intertek)
// Enable support by passing V9261F_SUPPORT=1 build flag
//--------------------------------------------------------------------------------

#ifndef V9261F_SUPPORT
#define V9261F_SUPPORT              0
#endif

#define V9261F_SYNC_INTERVAL        600
#define V9261F_REPORT_INTERVAL      60000

#define V9261F_BAUDRATE             4800

#define V9261F_CURRENT_FACTOR       81156358
#define V9261F_VOLTAGE_FACTOR       4178508
#define V9261F_POWER_FACTOR         157859
#define V9261F_RPOWER_FACTOR        V9261F_CURRENT_FACTOR

//--------------------------------------------------------------------------------
// Internal power montior
// Enable support by passing ADC_VCC_ENABLED=1 build flag
// Do not enable this if using the analog GPIO for any other thing
//--------------------------------------------------------------------------------

#ifndef ADC_VCC_ENABLED
#define ADC_VCC_ENABLED             1
#endif

#if ADC_VCC_ENABLED
    ADC_MODE(ADC_VCC);
#endif
