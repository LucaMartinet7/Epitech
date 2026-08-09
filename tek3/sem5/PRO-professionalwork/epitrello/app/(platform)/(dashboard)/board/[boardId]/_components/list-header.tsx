"use client";

import { List } from "@prisma/client";
import { FormInput } from "@/components/form/form-input";
import { useState, useRef, ElementRef } from "react";
import { useEventListener } from "usehooks-ts";
import { useAction } from "@/hooks/use-action";
import { updateList } from "@/actions/update-list";
import { toast } from "sonner";
import { ListOptions } from "./list-options";

interface ListHeaderProps {
    data: List;
    onAddCard: () => void;
};

export const ListHeader = ({data, onAddCard }:ListHeaderProps) => {
    const [title, setTitle] = useState(data.title);
    const [isEditing, setIsEditing] = useState(false);
    const formRef = useRef<ElementRef<"form">>(null);
    const inputRef = useRef<ElementRef<"input">>(null);

    const enableEditing = () => {
        setIsEditing(true);
        setTimeout(() => {
            inputRef.current?.focus();
            inputRef.current?.select();
        });
    };

    const disableEditing = () => setIsEditing(false);

    const { execute } = useAction(updateList, {
        onSuccess: (data) => {
            setTitle(data.title);
            toast.success("List title updated successfully");
            disableEditing();
        },
        onError: (error) => {
            console.error("Failed to update list title", error);
            toast.error("Failed to update list title");
        },
    });

    const handleSubmit = (formData: FormData) => {
        const title = formData.get("title") as string;
        const id = formData.get("id") as string;
        const boardId = formData.get("BoardId") as string;
        if (title === data.title) {
            return disableEditing();
        }
        execute({ title, id, boardId });
    }

    const onBlur = () => {
        formRef.current?.requestSubmit();
    }

    useEventListener("keydown", (e: KeyboardEvent) => {
        if (e.key === "Escape") {
            formRef.current?.requestSubmit();
        }
    });

    return (
        <div className="pt-2 px-2 text-sm font-semibold flex justify-between items-start gap-x-2">
            {isEditing ? (
                <form className="flex-1 px-[2px]" ref={formRef} action={handleSubmit}>
                    <input hidden id="id" name="id" value={data.id} />
                    <input hidden id="boardId" name="BoardId" value={data.boardId} />
                    <FormInput onBlur={onBlur} ref={inputRef} id="title" placeholder="Enter list title..." defaultValue={title} className="text-sm px-[7px] py-1 font-medium border-transparent hover:border-input focus:border-input transtition truncate bg-transparent focus:bg-white"/>
                    <button type="submit" className="hidden"></button>
                </form>) : (
            <div onClick={enableEditing} className="w-full text-sm px-2.5 py-1 h-7 font-medium border-transparent">
                {title}
            </div>
            )}
            <ListOptions data={data} onAddCard={onAddCard}/>
        </div>
    );
}