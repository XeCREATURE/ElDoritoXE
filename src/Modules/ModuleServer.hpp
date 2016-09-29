namespace Modules
{
	class ModuleServer : public Utils::Singleton<ModuleServer>, public ModuleBase
	{
	public:
		Command* VarServerSetAltMap;
		Command* VarServerSetAltMapClient;
		Command* VarServerSetBiped;
		Command* VarServerSetBipedClient;
		Command* VarServerSetEffects;
		Command* VarServerSetEffectsClient;
		Command* VarServerSetGravity;
		Command* VarServerSetGravityClient;
	};
}
