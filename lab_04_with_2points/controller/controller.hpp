#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "button/elevator_button/elevator_button.hpp"
#include "button/floor_button/floor_button.hpp"
#include "cabin_new/cabin.h"
#include "config.hpp"
#include <QObject>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);

signals:
    void stopCabinSignal(cabin_id_t cabin_id);
    void moveCabinUpSignal(cabin_id_t cabin_id);
    void moveCabinDownSignal(cabin_id_t cabin_id);
    void freeCabinSignal(cabin_id_t cabin_id);

    void reachFloorSignal();
    void controller_freed();
    void free_controller_signal();

    // NOTE(Talkasi): For more convinient testing
    void controller_cabin_button_change(int floor_n, cabin_id_t cabin_id, bool is_active);
    void controller_floor_button_change(int floor_n, direction_id_t direction_id, bool is_active);

public slots:
    void free_controller();
    void new_floor_destination(int floor_n, direction_t direction);
    void new_cabin_destination(int floor_n, cabin_id_t cabin_id);
    void reach_floor(int floor_n, cabin_id_t cabin_id);
    void manage_cabin();

    // NOTE(Talkasi): For more convinient testing
    void floor_button_change(int floor_n, direction_id_t direction_id, bool is_active);
    void cabin_button_change(int floor_n, cabin_id_t cabin_id, bool is_active);


private:
    int get_next_visit_point(cabin_id_t cabin_id);
    direction_t get_next_direction(cabin_id_t cabin_id);

    enum controller_state_t
    {
        FREE,
        MANAGING_NEW_FLOOR_DEST,
        MANAGING_NEW_CABIN_DEST,
        REACH_FLOOR,
        MANAGING_CABIN,
    };

    controller_state_t _state;
    std::unique_ptr<Cabin> cabin[N_CABINS] = {};
    bool to_visit[N_CABINS][N_FLOORS] = {};

    int cur_floor_i[N_CABINS] = {};
    direction_t cur_direction[N_CABINS] = {};

    std::shared_ptr<FloorButton> floor_buttons[N_DIRECTIONS][N_FLOORS];
    std::shared_ptr<ElevatorButton> elevator_buttons[N_CABINS][N_FLOORS];
};

#endif // CONTROLLER_H
