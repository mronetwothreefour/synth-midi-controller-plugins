#pragma once



struct UndoManager_Singleton
{
	UndoManager undoManager;

	UndoManager_Singleton(UndoManager_Singleton&&) = delete;
	UndoManager_Singleton& operator=(UndoManager_Singleton&&) = delete;

	static UndoManager* get() {
		static UndoManager_Singleton undoManager_Singleton;
		return &undoManager_Singleton.undoManager;
	}

private:
	UndoManager_Singleton() {
	}

	~UndoManager_Singleton() {
	}

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(UndoManager_Singleton)
};