#include "Inspector.hpp"
#include <GUI/Text.hpp>
#include <GUI/Layout.hpp>
#include <GUI/Input.hpp>
#include <GUI/Separator.hpp>

Bebr::Engine::Inspectable::Inspectable(Type type, void* data)
    : m_type(type)
    , m_data(data)
{}

Bebr::Engine::Inspectable::Type Bebr::Engine::Inspectable::GetType() const
{
    return m_type;
}

void* Bebr::Engine::Inspectable::GetData() const
{
    return m_data;
}

Bebr::Engine::Inspector::Inspector()
    : ClosableWindow("Inspector")
    , m_inspectable(Inspectable::Type::Nothing)
{}

void Bebr::Engine::Inspector::Render()
{
    if (!Begin())
    {
        End();
        return;
    }
    void* data = m_inspectable.GetData();
    if (data == nullptr)
    {
        InspectNothing();
        End();
        return;
    }

    const Inspectable::Type type = m_inspectable.GetType();
    switch (type)
    {
        case Bebr::Engine::Inspectable::Type::Nothing:
        InspectNothing();
        break;
        case Bebr::Engine::Inspectable::Type::InstanceLayer:
        InspectInstanceLayer(reinterpret_cast<Core::InstanceLayer*>(data));
        break;
        case Bebr::Engine::Inspectable::Type::Instance:
        InspectInstance(reinterpret_cast<Core::Instance*>(data));
        break;
    }

    End();
}

void Bebr::Engine::Inspector::SetInspectable(const Inspectable& inspectable)
{
    m_inspectable = inspectable;
}

void Bebr::Engine::Inspector::InspectNothing()
{
    static GUI::Text mainText("nothing is selected");

    System::Vector2F_t winSize = GetSize();
    System::Vector2F_t textSize = mainText.GetSize();

    System::Vector2F_t textPos = System::Vector2F_t((winSize.x - textSize.x) * 0.5f,
                                                    (winSize.y - textSize.y) * 0.5f);
    GUI::Layout::SetCurrentPosition(textPos);
    mainText.Render();
}

void Bebr::Engine::Inspector::InspectInstance(Core::Instance* instance)
{
    GUI::InputText nameField("Name", instance->GetName());
    GUI::Separator::LineWText("Instance");
    nameField.Render();
    instance->SetName(nameField.GetData());
    GUI::Separator::LineWText("Components");
    GUI::Text message("Components' content here");
    message.Render();
}

void Bebr::Engine::Inspector::InspectInstanceLayer(Core::InstanceLayer* instanceLayer)
{
    GUI::InputText nameField("Name", instanceLayer->GetName());
    nameField.AddFlag(GUI::InputText::Flag::EnterReturnsTrue);
    GUI::Separator::LineWText("Instance Layer");
    if (nameField.Render() && nameField.IsDeactivatedAfterEdit())
    {
        instanceLayer->SetName(nameField.GetData());
    }
}
