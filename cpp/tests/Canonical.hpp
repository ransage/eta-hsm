// Canonical.hpp

// CDPlayer.cpp
#include "eta/chrono/FakeLocalClock.hpp"
#include "eta/hsm/Hsm.hpp"
#include "TestLog.hpp"
#include <chrono>

namespace eta {
namespace hsm {
namespace canonical {

enum class CanonicalEvent
{
    // events with (default) external transition semantics
    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H,

    // same events with local transition semantics
    A_LOCAL,
    B_LOCAL,
    C_LOCAL,
    D_LOCAL,
    E_LOCAL,
    F_LOCAL,
    G_LOCAL,
    H_LOCAL,

    Z, // not part of typical example
};

enum class CanonicalState
{
    eTop,
    eS0,
    eS1,
    eS11,
    eS12,
    eS2,
    eS21,
    eS211,
};

using Clock = eta::chrono::FakeLocalClock<>;

class Canonical : public StateMachine<Canonical, hsm::StateMachineTraits<CanonicalEvent, CanonicalState, Clock>>
{
public:
    using Input = EmptyType;
    Canonical();
private:
};


template<CanonicalState kState>
using CanonicalTraits = StateTraits<Canonical, CanonicalState, kState>;

using Top = eta::hsm::TopState<CanonicalTraits<CanonicalState::eTop>>;
using S0 = eta::hsm::CompState<CanonicalTraits<CanonicalState::eS0>, Top>;
using S1 = eta::hsm::CompState<CanonicalTraits<CanonicalState::eS1>, S0>;
using S11 = eta::hsm::LeafState<CanonicalTraits<CanonicalState::eS11>, S1>;
using S12 = eta::hsm::LeafState<CanonicalTraits<CanonicalState::eS12>, S1>; // not part of typical example
using S2 = eta::hsm::CompState<CanonicalTraits<CanonicalState::eS2>, S0>;
using S21 = eta::hsm::CompState<CanonicalTraits<CanonicalState::eS21>, S2>;
using S211 = eta::hsm::LeafState<CanonicalTraits<CanonicalState::eS211>, S21>;

} // namespace canonical
} // namespace hsm
} // namespace eta
