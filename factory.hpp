/**
 * @author gh Corgice @IceSandwich
 * @date Jun 2023
 * @license MIT
 */

#pragma once

#include <unordered_map>
#include <memory>
#include <functional>
#include <string_view>
#include <iostream>

// TODO: __PRETTY_FUNCTION__ 每个平台不一样，需要适配，目前项目使用的是GUNC，Intelisense错误显示clang
//#if defined(__clang__)
//#define PRETTY_FUNCTION_NAME __PRETTY_FUNCTION__
//#define OFFSET 2
//#elif defined(__GNUC__)
//#define PRETTY_FUNCTION_NAME __PRETTY_FUNCTION__
//#define OFFSET 51
//#elif defined(_MSC_VER)
//#define PRETTY_FUNCTION_NAME __FUNCSIG__
//#define OFFSET 17
//#endif

//#ifdef __clang__
//name = __PRETTY_FUNCTION__;
//prefix = "auto type_name() [T = ";
//suffix = "]";
//#elif defined(__GNUC__)
//name = __PRETTY_FUNCTION__;
//prefix = "constexpr auto type_name() [with T = ";
//suffix = "]";
//#elif defined(_MSC_VER)
//name = __FUNCSIG__;
//prefix = "auto __cdecl type_name<";
//suffix = ">(void) noexcept";
//#endif

/**
* @brief 工厂基类
* @param FactoryClass 工厂类
* @param Args Product的构造函数参数
**/
template <typename FactoryClass, typename ...Args>
class Factory {
	using KeyType = std::string;
protected:
	using MappingType = std::unordered_map < KeyType, std::function<std::unique_ptr<FactoryClass>(Args ...)> >;
	static MappingType &getMappingInstance() {
		static MappingType instance;
		return instance;
	}
public:
	static void PrintRegisteredClassName() {
		constexpr std::string_view prettyName = __PRETTY_FUNCTION__;
		constexpr std::string_view classTag = "FactoryClass = ";
		constexpr std::size_t Tbegin = prettyName.find(classTag) + classTag.size();
		constexpr std::size_t Tend = prettyName.find(';', Tbegin);
		constexpr std::string_view typeNameView = prettyName.substr(Tbegin, Tend - Tbegin);
		std::cout << "Registered class " << typeNameView << " list:" << std::endl;
		for (auto &&[key, value] : getMappingInstance()) {
			std::cout << '\t' << key << std::endl;
		}
	}

	/**
	* @brief 产品基类
	* @param InstanceClass 产品类
	**/
	template <typename InstanceClass>
	class Registrar : public FactoryClass {
	protected:
		Registrar() {
			(void)registered;
		}
		static const bool registered;
	public:
		static constexpr std::string_view GetRegistrarClassName() {
			constexpr std::string_view prettyName = __PRETTY_FUNCTION__;
			constexpr std::string_view instanceClassTag = "InstanceClass = ";
			constexpr std::size_t Tbegin = prettyName.find(instanceClassTag) + instanceClassTag.size();
			constexpr std::size_t Tend = prettyName.find(';', Tbegin);
			constexpr std::string_view typeNameView = prettyName.substr(Tbegin, Tend - Tbegin);
			return typeNameView;
		}
		static std::unique_ptr<FactoryClass> Create(Args&&... args) {
			//static_assert(decltype(InstanceClass{ args... }), "error");
			return std::unique_ptr<FactoryClass>{ new InstanceClass(std::forward<Args>(args)...) };
		}
	};

	static std::unique_ptr<FactoryClass> Make(KeyType key, Args ...args) {
		return getMappingInstance().at(key)(args...);
	}
};

template <typename FactoryClass, typename ...Args>
template <typename InstanceClass>
const bool Factory<FactoryClass, Args...>::Registrar<InstanceClass>::registered = []() {
	//std::cout << "registered: " << Registrar::GetRegistrarClassName() << std::endl;
	FactoryClass::getMappingInstance().insert(std::make_pair(std::string{ Registrar::GetRegistrarClassName() }, Registrar::Create));
	return true;
}();