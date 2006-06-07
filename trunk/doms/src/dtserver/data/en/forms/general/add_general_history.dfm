<Form title="Historia Clinica"  tables="doms_pacients doms_general_history" >
	<HBox>
		<Image filename="logo.svg" />
		<VBox>
			<Label text="Historia clinica" />
			<Input label="No." dbfield="doms_general_history:clinicHistory" />
			<Input label="Odontologo" dbfield="" />
		</VBox>
		<Input type="date" dbfield="doms_general_history:initDate" />
	</HBox>
	<VBox>
		<Input label="Motivo de consulta" dbfield="doms_general_history:reason" />
		<Input label="Remitido por"  dbfield="doms_general_history:remitedBy" />
	</VBox>
</Form>

